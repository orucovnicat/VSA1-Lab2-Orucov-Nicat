# Laboratoriya İşi № 2: Verilənlər Strukturlarının Tətbiqi və Analizi

## Məlumat
- Tələbə: Nicat Orucov[cite: 1]
- Qrup: KOM25A[cite: 1]
- Müəllim: Şamil Hümbətov[cite: 1]
- Mövzu: Linked List, Stack və Queue strukturlarının sıfırdan implementasiyası və analizi[cite: 2]
- Mənbə: Mark Allen Weiss, Data Structures and Algorithm Analysis in C++ (4th Edition)[cite: 2]

---

## 1. Tapşırıq 1: Smart Music Playlist (Doubly Linked List)

### Təsvir
STL kitabxanasından istifadə etmədən Doubly Linked List vasitəsilə musiqi pleylisti sistemi qurulmuşdur[cite: 2, 4, 6]. Sistem mahnı əlavə etmə, silmə, axtarış və irəli/geri naviqasiyanı dəstəkləyir[cite: 3, 4, 6].

### Eksperiment Nəticələri
| Element sayı (n) | Insert (ms) | Search (ms) | Delete (ms) |
| :--- | :--- | :--- | :--- |
| 100 | 0.1116 | 0.0076 | 0.0575 |
| 1000 | 0.8047 | 0.8714 | 4.9431 |
| 10000 | 12.7502 | 142.4560 | 480.2690 |
[cite: 5]

---

## 2. Tapşırıq 2: Browser History Manager (Stack)

### Təsvir
STL stack olmadan təkistiqamətli əlaqəli siyahı (Singly Linked List) əsasında LIFO mexanizminə uyğun brauzer tarixçəsi sistemi reallaşdırılmışdır[cite: 7, 8].

### Eksperiment Nəticələri
| Əməliyyat sayı (n) | Push (ms) | Pop (ms) |
| :--- | :--- | :--- |
| 100 | 0.1972 | 0.1923 |
| 1000 | 2.0462 | 16.8935 |
| 10000 | 32.7293 | 1221.3600 |
[cite: 8]

---

## 3. Tapşırıq 3: Airport Check-in Queue System (Queue)

### Təsvir
Sərnişin qeydiyyatı üçün FIFO prinsipi ilə işləyən iki göstəricili (front və rear) növbə strukturu STL istifadə edilmədən qurulmuşdur[cite: 2, 11, 12].

### Eksperiment Nəticələri
| Element sayı (n) | Enqueue (ms) | Dequeue (ms) | Peek (ms) |
| :--- | :--- | :--- | :--- |
| 100 | 0.1666 | 0.0778 | 0.0003 |
| 1000 | 0.7933 | 4.4105 | 0.0008 |
| 10000 | 11.8371 | 485.2510 | 0.0069 |
[cite: 12]

---

## 4. Əməliyyatların Müqayisəsi və Təhlil (n = 10000)

| Struktur | Əməliyyat | Ümumi (ms) | Orta (us) | Nəzəri | Nəticə |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Linked List | Insert | 12.7502 | 1.28 | O(1) | Uyğundur |
| Linked List | Search | 142.4560 | 14.20 | O(n) | Uyğundur |
| Linked List | Delete | 480.2690 | 48.00 | O(1)* | Uyğun deyil |
| Stack | Push | 32.7293 | 3.27 | O(1) | Uyğundur |
| Stack | Pop | 1221.3600 | 122.00 | O(1) | Uyğun deyil |
| Queue | Enqueue | 11.8371 | 1.18 | O(1) | Uyğundur |
| Queue | Dequeue | 485.2510 | 48.50 | O(1) | Uyğun deyil |
| Queue | Peek | 0.0069 | 0.00069 | O(1) | Uyğundur |
[cite: 16]

### Əsas Nəticələr
1. Əlavəetmə (Insert, Push, Enqueue) və Peek əməliyyatları nəzəri O(1) mürəkkəbliyini tam təsdiqləmişdir[cite: 16].
2. Axtarış (Search) əməliyyatı xətti O(n) xarakteri daşıdığından n artdıqca ümumi müddət kvadratik böyümüşdür[cite: 16].
3. Silmə (Delete, Pop, Dequeue) əməliyyatlarının nəzəri O(1) olmasına baxmayaraq yüksək vaxt aparması alqoritmdən deyil, ardıcıl `delete` çağırışları zamanı əməliyyat sisteminin dinamik yaddaş (heap) idarəetmə xərclərindən qaynaqlanır[cite: 13, 16].

---

## 5. Test Mühiti
- Model: Lenovo LOQ 15IRX9[cite: 15]
- Prosessor: Intel Core i5-13450HX[cite: 15]
- RAM: 24 GB[cite: 15]
- ƏS: Windows 11 Pro[cite: 15]
- Kompilyator: g++ 16.2.0[cite: 15]