<div align="center">

# 📡 BeyondWiFi
### Human Presence Detection using ESP32 Wi-Fi CSI & Machine Learning

![Python](https://img.shields.io/badge/Python-3.10+-blue?style=for-the-badge&logo=python)
![ESP32](https://img.shields.io/badge/ESP32-WiFi-red?style=for-the-badge&logo=espressif)
![Machine Learning](https://img.shields.io/badge/Machine-Learning-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-In%20Progress-orange?style=for-the-badge)

*"Detect humans without cameras by analyzing wireless signals."*

</div>

---

# 📖 Overview

BeyondWiFi is an open-source research project exploring **privacy-preserving human presence detection** using **ESP32 Wi-Fi Channel State Information (CSI)** and **Machine Learning**.

Instead of relying on cameras, BeyondWiFi learns how **wireless signals change when a person moves through the environment**, enabling real-time human sensing while preserving privacy.

---

# ✨ Features

- 📶 Wi-Fi CSI Collection using ESP32
- 🚶 Human Presence Detection
- 🚪 Entry / Exit Detection *(Planned)*
- 👥 Multiple Person Detection *(Research)*
- 🤖 Machine Learning Classification
- 📈 Signal Visualization
- ⚡ Real-Time Inference
- 🔒 Privacy-Friendly (No Camera)

---

# 🏗️ System Architecture

```text
               Wi-Fi Router
                    │
        ┌───────────┴───────────┐
        │                       │
    ESP32 #1               ESP32 #2
 (Transmitter)           (Receiver)
        │                       │
        └──── Wi-Fi CSI Data ───┘
                    │
             Data Collection
                    │
            Signal Processing
                    │
          Machine Learning Model
                    │
         Presence / Activity Result
```

---

# 🎯 Research Goals

| Phase | Objective | Status |
|--------|-----------|--------|
| Phase 1 | Human Presence Detection | 🟡 Planned |
| Phase 2 | Motion Detection | 🔲 Future |
| Phase 3 | Person Counting | 🔲 Research |
| Phase 4 | Gesture Recognition | 🔲 Research |
| Phase 5 | Real-Time Deployment | 🔲 Future |

---

# 🧠 How It Works

Traditional systems use cameras:

```
Camera
   ↓
Image
   ↓
YOLO
   ↓
Person
```

BeyondWiFi uses radio signals:

```
ESP32
   ↓
Wi-Fi CSI
   ↓
Signal Processing
   ↓
Machine Learning
   ↓
Person
```

No image is ever captured.

---

# 📂 Repository Structure

```
BeyondWiFi
│
├── data/
│   ├── raw/
│   ├── processed/
│   └── datasets/
│
├── esp32/
│   ├── transmitter/
│   └── receiver/
│
├── notebooks/
│
├── models/
│
├── scripts/
│   ├── preprocessing.py
│   ├── training.py
│   └── inference.py
│
├── docs/
│
├── results/
│
└── README.md
```

---

# 🛠️ Technology Stack

| Category | Tools |
|----------|------|
| Hardware | ESP32 |
| Wireless | Wi-Fi CSI |
| Programming | Python |
| Data Analysis | NumPy, Pandas |
| Visualization | Matplotlib |
| Machine Learning | Scikit-learn / PyTorch |
| Signal Processing | SciPy |

---

# 📊 Project Workflow

```
Collect CSI Data
        │
        ▼
Clean Dataset
        │
        ▼
Feature Extraction
        │
        ▼
Train Machine Learning Model
        │
        ▼
Evaluate
        │
        ▼
Deploy
```

---

# 🚀 Future Roadmap

- [ ] Human Presence Detection
- [ ] Motion Classification
- [ ] Multiple Person Detection
- [ ] Activity Recognition
- [ ] Gesture Detection
- [ ] Real-Time Dashboard
- [ ] MQTT Integration
- [ ] Edge AI Deployment
- [ ] TinyML Optimization

---

# 🔬 Potential Applications

- Smart Home
- Smart Office
- Elderly Monitoring
- Occupancy Detection
- Intrusion Detection
- Energy Saving Systems
- Contactless Automation

---

# 📸 Example Output

```text
---------------------------------
Wi-Fi CSI Monitoring
---------------------------------

Status      : Person Detected
Confidence  : 96.7%

Activity    : Walking

Timestamp   : 2026-08-07 22:31:18

---------------------------------
```

---

# 📚 References

- ESP32 CSI Tool
- Espressif ESP-IDF
- Wi-Fi CSI Research Papers
- TinyML
- Scikit-learn Documentation

---

# 🤝 Contributing

Contributions, discussions, and research ideas are welcome.

If you're interested in Wi-Fi sensing, machine learning, or embedded AI, feel free to open an issue or submit a pull request.

---

# ⭐ Star History

If you find this project useful, consider giving it a ⭐ to support the project.

---

<div align="center">

## Beyond Projects

| Repository | Focus |
|------------|-------|
| 🟦 BeyondYOLO | Computer Vision |
| 📡 BeyondWiFi | Wi-Fi Sensing |
| 📶 BeyondRadar *(Future)* | mmWave Sensing |
| 🎤 BeyondAudio *(Future)* | Audio Intelligence |

---

Made with ❤️ using ESP32, Wi-Fi CSI, and Machine Learning

</div>
