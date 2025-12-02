# ESP32 WiFi 掃描程式

## 專案簡介

這是一個基於 **ESP32** 微控制器的 **WiFi 網路掃描工具**，可以定期掃描並列出周圍環境中所有可用的 WiFi 網路名稱（SSID）。

## 功能特性

- 🔍 **WiFi 網路掃描** - 自動掃描附近的所有 WiFi 網路
- 📋 **SSID 列表** - 清晰顯示每個 WiFi 網路的名稱
- ⏱️ **定期更新** - 每 5 秒自動重新掃描一次
- 🪶 **輕量級** - 程式碼簡潔，資源佔用少

## 硬體需求

- **ESP32 開發板**（如 NodeMCU-32S）
- USB 連接線（用於上傳程式和序列通信）

## 軟體需求

- **PlatformIO**（VS Code 延伸模組）
- **Arduino 框架**（已在 `platformio.ini` 中配置）

## 專案結構

```
ESP32_wifi_scan-20251202/
├── platformio.ini      # PlatformIO 配置檔案
├── src/
│   └── main.cpp        # 主程式
├── include/            # 標頭檔案目錄
├── lib/                # 函式庫目錄
├── test/               # 測試目錄
└── README.md           # 本檔案
```

## 快速開始

### 1. 開啟專案
在 VS Code 中打開此專案資料夾。

### 2. 編譯程式
在 PlatformIO 終端中執行：
```bash
platformio run
```

### 3. 上傳到 ESP32
將 ESP32 連接到電腦，然後執行：
```bash
platformio run --target upload
```

### 4. 查看輸出
打開序列監視器（Serial Monitor）查看掃描結果：
```bash
platformio device monitor
```

設定波特率為 **9600** bps。

## 使用方法

上傳完成後，ESP32 會自動開始掃描 WiFi 網路。序列監視器將顯示類似以下輸出：

```
ESP32 WiFi SSID 掃描

找到 5 個 WiFi 網路:
1. HomeWiFi
2. OfficeNetwork
3. GuestWiFi
4. NeighborWiFi
5. PublicWiFi
```

## 程式碼說明

### 主要函數

#### `setup()`
- 初始化序列通信（波特率 9600）
- 設定 WiFi 為 Station（STA）模式
- 斷開任何現有連接

#### `loop()`
- 執行 WiFi 網路掃描
- 列印掃描結果
- 每 5 秒重複一次

### 關鍵 API

| 函數 | 功能 |
|------|------|
| `WiFi.mode(WIFI_STA)` | 設定 WiFi 為 Station 模式 |
| `WiFi.scanNetworks()` | 掃描附近的 WiFi 網路 |
| `WiFi.SSID(i)` | 取得第 i 個 WiFi 網路的 SSID |
| `WiFi.scanDelete()` | 釋放掃描結果記憶體 |

## 波特率設定

- **程式端**: 9600 bps（在 `main.cpp` 中設定）
- **監視器端**: 需要設定為 9600 bps 以正確顯示輸出

## 掃描間隔調整

要修改掃描頻率，編輯 `main.cpp` 中的以下行：

```cpp
delay(5000); // 修改此值（單位：毫秒），5000 = 5 秒
```

例如改為 `delay(10000)` 表示每 10 秒掃描一次。

## 常見問題

### Q: 序列監視器顯示亂碼
**A:** 檢查波特率是否設定為 9600 bps。

### Q: ESP32 未列出任何 WiFi 網路
**A:** 
1. 確認 WiFi 功能已正常工作
2. 檢查 ESP32 是否收到正確的電源
3. 嘗試靠近 WiFi 路由器

### Q: 程式上傳失敗
**A:**
1. 檢查 USB 連接是否正常
2. 確認在設備管理器中 COM 埠正確識別
3. 在 PlatformIO 中重新選擇正確的上傳埠

## 延伸功能建議

- 顯示信號強度（RSSI）
- 連接到特定的 WiFi 網路
- 保存 WiFi 掃描歷史記錄
- 使用 OLED 屏幕顯示結果

## 許可證

本專案開源免費使用。

## 作者

Created by chiangyih

## 更新日期

2025年12月2日
