# Proje: So Long

## İçindekiler

1. [Proje Tanımı](#proje-tanımı)
2. [Dosya Yapısı](#dosya-yapısı)
3. [Kullanılan Kütüphaneler](#kullanılan-kütüphaneler)
4. [Fonksiyonlar](#fonksiyonlar)
5. [Harita Formatı](#harita-formatı)
6. [Hata Yönetimi](#hata-yönetimi)
7. [Kullanım](#kullanım)
8. [Sonuç](#sonuç)

## Proje Tanımı

"So Long", oyuncunun belirli nesneleri toplaması ve çıkışa ulaşması gereken bir harita tabanlı oyundur. Proje, haritanın kontrolü, karakter hareketi ve kullanıcı arayüzü gibi temel oyun mekaniklerini içerir. 

## Kullanılan Kütüphaneler

Proje, grafik işlemleri için MinilibX kütüphanesini ve dosya okuma işlemleri için `get_next_line` kütüphanesini kullanmaktadır.

## Fonksiyonlar

### 1. Harita Kontrol Fonksiyonları

- **`check_char`**: Harita üzerindeki karakterleri kontrol eder (C, P, E, 1, 0).
- **`check_rect`**: Haritanın dikdörtgen şeklinde olup olmadığını kontrol eder.
- **`check_path`**: Oyuncunun harita üzerinde geçerli bir yol bulup bulamadığını kontrol eder.

### 2. Harita Okuma Fonksiyonları

- **`ft_read_map`**: Harita dosyasını okuyarak, haritanın boyutunu belirler.
- **`set_mapy_and_malloc`**: Harita boyutunu belirler ve dinamik bellek ayırır.

### 3. Yardımcı Fonksiyonlar

- **`ft_lstrlen`**: Bir string'in uzunluğunu döndürür.
- **`ft_itoa`**: Tam sayıyı string'e çevirir.

## Harita Formatı

Harita dosyaları `.ber` uzantısına sahiptir ve belirli karakterlerle tanımlanmıştır:
- `1`: Duvar
- `0`: Boş alan
- `C`: Toplanabilir nesne
- `P`: Başlangıç noktası (oyuncu)
- `E`: Çıkış noktası

Proje, harita okunamazsa veya geçersiz bir harita bulunursa hata mesajları verir. Bu, oyuncunun daha iyi bir deneyim yaşamasını sağlar.

## Kullanım

Projeyi derlemek için terminalde aşağıdaki komutları çalıştırabilirsiniz:

```bash
make


