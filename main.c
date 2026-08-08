#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "nvs_flash.h"

#include "esp_log.h"
#include "esp_wifi.h"
#include "esp_event.h"

static const char *TAG = "BeyondWiFi";

/*
 * CSI callback
 *
 * This function is called every time
 * the ESP32 receives CSI information.
 */
static void wifi_csi_rx_cb(void *ctx, wifi_csi_info_t *info)
{
    if (info == NULL || info->buf == NULL) {
        return;
    }

    printf("CSI,");

    // RSSI
    printf("rssi=%d,", info->rx_ctrl.rssi);

    // Noise floor
    printf("noise=%d,", info->rx_ctrl.noise_floor);

    // CSI length
    printf("len=%d,", info->len);

    // Raw CSI values
    printf("data=");

    for (int i = 0; i < info->len; i++) {
        printf("%d", info->buf[i]);

        if (i < info->len - 1) {
            printf(",");
        }
    }

    printf("\n");
}


static void wifi_init(void)
{
    /*
     * Initialize NVS
     */
    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
        ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {

        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    /*
     * Initialize TCP/IP stack
     */
    ESP_ERROR_CHECK(esp_netif_init());

    /*
     * Create default event loop
     */
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /*
     * Create default Wi-Fi station
     */
    esp_netif_create_default_wifi_sta();

    /*
     * Initialize Wi-Fi
     */
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    /*
     * Set station mode
     */
    ESP_ERROR_CHECK(
        esp_wifi_set_mode(WIFI_MODE_STA)
    );

    /*
     * Start Wi-Fi
     */
    ESP_ERROR_CHECK(
        esp_wifi_start()
    );

    /*
     * Enable promiscuous mode.
     *
     * This allows the ESP32 to receive
     * more Wi-Fi frames for CSI collection.
     */
    ESP_ERROR_CHECK(
        esp_wifi_set_promiscuous(true)
    );

    /*
     * Configure CSI
     */
    wifi_csi_config_t csi_config = {
        .lltf_en = true,
        .htltf_en = true,
        .stbc_htltf2_en = true,
        .ltf_merge_en = true,
        .channel_filter_en = false,
        .manu_scale = false,
        .shift = 0,
    };

    ESP_ERROR_CHECK(
        esp_wifi_set_csi_config(&csi_config)
    );

    /*
     * Register CSI callback
     */
    ESP_ERROR_CHECK(
        esp_wifi_set_csi_rx_cb(wifi_csi_rx_cb, NULL)
    );

    /*
     * Enable CSI
     */
    ESP_ERROR_CHECK(
        esp_wifi_set_csi(true)
    );

    ESP_LOGI(TAG, "CSI enabled");
}


void app_main(void)
{
    ESP_LOGI(TAG, "BeyondWiFi starting...");

    wifi_init();

    ESP_LOGI(TAG, "CSI receiver ready");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
