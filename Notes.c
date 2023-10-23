`memset` fonksiyonu, C dilinde bir bellek bloğunun ilk `n` karakterini belirli bir karakterle doldurmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `void *memset(void *str, int c, size_t n)`¹. `str` parametresi, doldurulacak bellek bloğunu gösteren bir işaretçidir.
`c` parametresi, bellek bloğunun ilk `n` karakterine kopyalanacak karakterdir. `n` parametresi ise kopyalanacak maksimum karakter sayısını belirtir¹.

İşte bir örnek:

int main(void) {
    char str[] = "Hello World";
    printf("Original string: %s\n", str);
    memset(str, 'x', 5);
    printf("Modified string: %s\n", str);
    return 0;
}
```
Bu programda, `memset` fonksiyonu ile bir karakter dizisinin ilk 5 karakterinin yerine 'x' karakteri koyulur ve dizi içeriği ekrana yazdırılır.
Programın çıktısı şu şekildedir:
```
Original string: Hello World
Modified string: xxxxx World
```

void *my_memset(void *str, int c, size_t n) {
    unsigned char *ptr = (unsigned char *) str;
    while (n-- > 0) {
        *ptr++ = (unsigned char) c;
    }
    return str;
}
```
Bu fonksiyon, `memset` fonksiyonunun basit bir uygulamasıdır. `str` parametresi, doldurulacak bellek bloğunu gösteren bir işaretçidir.
`c` parametresi, bellek bloğunun ilk `n` karakterine kopyalanacak karakterdir. `n` parametresi ise kopyalanacak maksimum karakter sayısını belirtir.
Fonksiyon, bellek bloğunu doldurduktan sonra `str` işaretçisini geri döndürür.
----------------------------------------------------------------------------------------------------------------------------------------------
`bzero` fonksiyonu, C dilinde bir bellek bloğunun ilk `n` baytını sıfırlar (yani '\\0' içeren baytlarla doldurur)¹.
Bu fonksiyon, `s` tarafından belirtilen konumdan başlayarak bellekteki `n` baytlık veriyi siler¹. 
Ancak, `bzero` fonksiyonu artık kullanılmamaktadır ve yerine genellikle `memset` fonksiyonu kullanılır²³.
Bu nedenle, yeni programlar yazarken `memset` fonksiyonunu kullanmanız önerilir³.
Aşağıda, `bzero` fonksiyonunun `memset` ile nasıl değiştirileceğine dair bir örnek verilmiştir:

// void bzero(void *s, size_t n);
#define bzero(s, n) memset((s), 0, (n))
```
Bu kod parçacığı, `bzero` fonksiyonunun yerine `memset` fonksiyonunu kullanarak bellek bloğunu sıfırlar.
Bu durumda, `memset` fonksiyonu `(s)` işaretçisi tarafından belirtilen bellek bloğunu `(n)` bayt boyunca sıfırlar.
----------------------------------------------------------------------------------------------------------------------------------------------
`memcpy` fonksiyonu, C dilinde bir bellek bloğundan diğerine belirli bir sayıda bayt kopyalamak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `void *memcpy(void *dest, const void *src, size_t n)`¹.
`dest` parametresi, kopyalama işleminin yapılacağı hedef bellek bloğunu gösteren bir işaretçidir.
`src` parametresi, kopyalanacak verinin bulunduğu kaynak bellek bloğunu gösteren bir işaretçidir. `n` parametresi ise kopyalanacak bayt sayısını belirtir¹.
`memcpy` fonksiyonu, hedef ve kaynak bellek bloklarının çakışması durumunda tanımsız davranışa neden olabilir.
Bu nedenle, çakışan bellek blokları arasında veri kopyalamak için `memmove` fonksiyonu kullanılması önerilir.

İşte bir örnek:

int main(void) {
    char src[] = "Hello World";
    char dest[11];
    memcpy(dest, src, 11);
    printf("Copied string: %s\n", dest);
    return 0;
}
```
Bu programda, `memcpy` fonksiyonu ile bir karakter dizisindeki karakterlerin tamamı başka bir karakter dizisine kopyalanır ve kopyalanan dizi ekrana yazdırılır.
Programın çıktısı şu şekildedir:
```
Copied string: Hello World
```
----------------------------------------------------------------------------------------------------------------------------------------------
`memmove` fonksiyonu, C dilinde bir bellek bloğundan diğerine belirli bir sayıda bayt kopyalamak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `void *memmove(void *dest, const void *src, size_t n)`.
`dest` parametresi, kopyalama işleminin yapılacağı hedef bellek bloğunu gösteren bir işaretçidir.
`src` parametresi, kopyalanacak verinin bulunduğu kaynak bellek bloğunu gösteren bir işaretçidir. `n` parametresi ise kopyalanacak bayt sayısını belirtir¹.
`memmove` fonksiyonu, hedef ve kaynak bellek bloklarının çakışması durumunda bile doğru bir şekilde çalışır².
Bu nedenle, çakışan bellek blokları arasında veri kopyalamak için `memmove` fonksiyonu kullanılması önerilir².

İşte bir örnek:

int main(void) {
    char str[] = "Hello World";
    printf("Original string: %s\n", str);
    memmove(str + 6, str + 4, 5);
    printf("Modified string: %s\n", str);
    return 0;
}
```
Bu programda, `memmove` fonksiyonu ile bir karakter dizisindeki karakterlerin bir kısmı başka bir konuma kopyalanır ve dizi içeriği ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
Original string: Hello World
Modified string: Helloo Worl
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strlcpy` fonksiyonu, bir kaynak dizisinden belirli bir sayıda karakteri hedef diziye güvenli bir şekilde kopyalamak için kullanılır.
Bu fonksiyon, `strcpy` fonksiyonunun daha güvenli, daha tutarlı ve daha az hata yapma eğiliminde olan bir alternatifidir.
`strlcpy` fonksiyonunun bildirimi şu şekildedir: `size_t strlcpy(char *dst, const char *src, size_t size)`².
`dst` parametresi, kopyalama işleminin yapılacağı hedef diziyi gösteren bir işaretçidir. `src` parametresi, kopyalanacak verinin bulunduğu kaynak diziyi gösteren bir işaretçidir.
`size` parametresi ise hedef dizinin boyutunu belirtir².
`strlcpy` fonksiyonu, kaynak dizinin NUL ile sonlandırılmış olduğunu varsayar ve hedef dizinin boyutundan en fazla 1 eksik karakter kopyalar².
Kopyalama işlemi tamamlandıktan sonra hedef dizi NUL ile sonlandırılır². Bu fonksiyon, kopyalama işlemi sırasında hedef dizinin taşmasını önler².

İşte bir örnek:

int main(void) {
    char src[] = "Hello World";
    char dest[6];
    strlcpy(dest, src, sizeof(dest));
    printf("Copied string: %s\n", dest);
    return 0;
}
```
Bu programda, `strlcpy` fonksiyonu ile bir karakter dizisindeki karakterlerin bir kısmı başka bir karakter dizisine güvenli bir şekilde kopyalanır ve kopyalanan dizi ekrana yazdırılır.
Programın çıktısı şu şekildedir:
```
Copied string: Hello
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strlcat` fonksiyonu, bir kaynak dizisinden belirli bir sayıda karakteri hedef diziye güvenli bir şekilde eklemek için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `size_t strlcat(char *dst, const char *src, size_t size)`.
`dst` parametresi, eklemenin yapılacağı hedef diziyi gösteren bir işaretçidir. `src` parametresi, eklenen verinin bulunduğu kaynak diziyi gösteren bir işaretçidir.
`size` parametresi ise hedef dizinin boyutunu belirtir¹.
`strlcat` fonksiyonu, NUL ile sonlandırılmış `src` dizisini `dst` dizisinin sonuna ekler.
En fazla `size - strlen(dst) - 1` bayt ekler ve sonucu NUL ile sonlandırır¹. 
`strlcpy` ve `strlcat` fonksiyonları oluşturmaya çalıştıkları dizenin toplam uzunluğunu döndürürler.
`strlcpy` için bu, `src` nin uzunluğu anlamına gelir. `strlcat` için bu, `dst`'nin başlangıçtaki uzunluğu ve `src`'nin uzunluğunun toplamı anlamına gelir¹.

Aşağıda, `strlcat` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    char dst[20] = "Hello";
    const char src[] = " World";
    strlcat(dst, src, sizeof(dst));
    printf("Concatenated string: %s\n", dst);
    return 0;
}
```
Bu programda, `strlcat` fonksiyonu ile bir karakter dizisindeki karakterlerin tamamı başka bir karakter dizisinin sonuna güvenli bir şekilde eklenir ve oluşan dizi ekrana yazdırılır.
Programın çıktısı şu şekildedir:
```
Concatenated string: Hello World
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strchr` fonksiyonu, C dilinde bir karakter dizisinde belirli bir karakterin ilk kez geçtiği yeri bulmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `char *strchr(const char *str, int c)`³. `str` parametresi, taranacak C dizisini gösterir.
`c` parametresi ise `str` içinde aranacak karakterdir².
Bu fonksiyon, `str` tarafından belirtilen karakter dizisinde `c` karakterinin (bir `unsigned char` olarak) ilk kez geçtiği yeri arar.
Bu fonksiyon, `str` dizisinde `c` karakterinin ilk kez geçtiği yeri gösteren bir işaretçi döndürür veya karakter bulunamazsa `NULL` döndürür².
Aşağıda, `strchr` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    const char str[] = "https://www.tutorialspoint.com";
    const char ch = '.';
    char *ret;
    ret = strchr(str, ch);
    printf("String after |%c| is - |%s|\n", ch, ret);
    return 0;
}
```
Bu programda, `strchr` fonksiyonu ile bir karakter dizisinde belirli bir karakterin ilk kez geçtiği yer bulunur ve bulunan yerden sonraki dizi ekrana yazdırılır.
Programın çıktısı şu şekildedir:
```
String after |.| is - |.tutorialspoint.com|
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strrchr` fonksiyonu, C dilinde bir karakter dizisinde belirli bir karakterin son kez geçtiği yeri bulmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `char *strrchr(const char *str, int c)`. `str` parametresi, taranacak C dizisini gösterir.
`c` parametresi ise `str` içinde aranacak karakterdir.
Bu fonksiyon, `str` tarafından belirtilen karakter dizisinde `c` karakterinin (bir `unsigned char` olarak) son kez geçtiği yeri arar.
Bu fonksiyon, `str` dizisinde `c` karakterinin son kez geçtiği yeri gösteren bir işaretçi döndürür veya karakter bulunamazsa `NULL` döndürür.
Aşağıda, `strrchr` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    const char str[] = "https://www.tutorialspoint.com";
    const char ch = '.';
    char *ret;
    ret = strrchr(str, ch);
    printf("String after |%c| is - |%s|\n", ch, ret);
    return 0;
}
```
Bu programda, `strrchr` fonksiyonu ile bir karakter dizisinde belirli bir karakterin son kez geçtiği yer bulunur ve bulunan yerden sonraki dizi ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
String after |.| is - |.com|
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strncmp` fonksiyonu, C dilinde iki karakter dizisini belirli bir sayıda karaktere kadar karşılaştırmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `int strncmp(const char *str1, const char *str2, size_t n)`.
`str1` ve `str2` parametreleri, karşılaştırılacak iki C dizisini gösterir. `n` parametresi ise karşılaştırılacak maksimum karakter sayısını belirtir.

Bu fonksiyon, `str1` ve `str2` tarafından belirtilen iki C dizisini ilk `n` karaktere kadar karşılaştırır.
Eğer `str1` dizisi, `str2` dizisinden daha küçükse, fonksiyon negatif bir değer döndürür. Eğer `str1` dizisi, `str2` dizisinden daha büyükse, fonksiyon pozitif bir değer döndürür.
Eğer iki dizi eşitse, fonksiyon 0 döndürür.
Aşağıda, `strncmp` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    char str1[] = "abcdef";
    char str2[] = "abcxyz";
    int result;
    result = strncmp(str1, str2, 3);
    if (result == 0) {
        printf("First 3 characters of both strings are equal\n");
    } else {
        printf("First 3 characters of both strings are different\n");
    }
    return 0;
}
```
Bu programda, `strncmp` fonksiyonu ile iki karakter dizisinin ilk 3 karakteri karşılaştırılır ve sonuç ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
First 3 characters of both strings are equal
```
----------------------------------------------------------------------------------------------------------------------------------------------
`memchr` fonksiyonu, C dilinde bir bellek bloğunda belirli bir karakterin ilk kez geçtiği yeri bulmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `void *memchr(const void *str, int c, size_t n)`. `str` parametresi, taranacak bellek bloğunu gösterir.
`c` parametresi ise `str` içinde aranacak karakterdir. `n` parametresi ise taranacak maksimum bayt sayısını belirtir.
Bu fonksiyon, `str` tarafından belirtilen bellek bloğunda `c` karakterinin (bir `unsigned char` olarak) ilk kez geçtiği yeri arar.
Bu fonksiyon, `str` bellek bloğunda `c` karakterinin ilk kez geçtiği yeri gösteren bir işaretçi döndürür veya karakter bulunamazsa `NULL` döndürür.
Aşağıda, `memchr` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    const char str[] = "https://www.tutorialspoint.com";
    const char ch = '.';
    char *ret;
    ret = memchr(str, ch, strlen(str));
    printf("String after |%c| is - |%s|\n", ch, ret);
    return 0;
}
```
Bu programda, `memchr` fonksiyonu ile bir bellek bloğunda belirli bir karakterin ilk kez geçtiği yer bulunur ve bulunan yerden sonraki dizi ekrana yazdırılır.
Programın çıktısı şu şekildedir:
```
String after |.| is - |.tutorialspoint.com|
```
----------------------------------------------------------------------------------------------------------------------------------------------
`memcmp` fonksiyonu, C dilinde iki bellek bloğunu belirli bir sayıda bayt kadar karşılaştırmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `int memcmp(const void *str1, const void *str2, size_t n)`.
`str1` ve `str2` parametreleri, karşılaştırılacak iki bellek bloğunu gösterir. `n` parametresi ise karşılaştırılacak maksimum bayt sayısını belirtir.
Bu fonksiyon, `str1` ve `str2` tarafından belirtilen iki bellek bloğunu ilk `n` bayta kadar karşılaştırır.
Eğer `str1` bloğu, `str2` bloğundan daha küçükse, fonksiyon negatif bir değer döndürür.
Eğer `str1` bloğu, `str2` bloğundan daha büyükse, fonksiyon pozitif bir değer döndürür. Eğer iki bellek bloğu eşitse, fonksiyon 0 döndürür.
Aşağıda, `memcmp` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    char str1[] = "abcdef";
    char str2[] = "abcxyz";
    int result;
    result = memcmp(str1, str2, 3);
    if (result == 0) {
        printf("First 3 bytes of both memory blocks are equal\n");
    } else {
        printf("First 3 bytes of both memory blocks are different\n");
    }
    return 0;
}
```
Bu programda, `memcmp` fonksiyonu ile iki bellek bloğunun ilk 3 baytı karşılaştırılır ve sonuç ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
First 3 bytes of both memory blocks are equal
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strnstr` fonksiyonu, C dilinde bir karakter dizisinde belirli bir alt dizinin ilk kez geçtiği yeri bulmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `char *strnstr(const char *haystack, const char *needle, size_t len)`.
`haystack` parametresi, taranacak C dizisini gösterir. `needle` parametresi ise `haystack` içinde aranacak alt diziyi gösterir.
`len` parametresi ise taranacak maksimum karakter sayısını belirtir.
Bu fonksiyon, `haystack` tarafından belirtilen karakter dizisinde `needle` alt dizisinin ilk kez geçtiği yeri arar.
Bu fonksiyon, `haystack` dizisinde `needle` alt dizisinin ilk kez geçtiği yeri gösteren bir işaretçi döndürür veya alt dizi bulunamazsa `NULL` döndürür.
Aşağıda, `strnstr` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    const char haystack[] = "https://www.tutorialspoint.com";
    const char needle[] = "point";
    char *ret;
    ret = strnstr(haystack, needle, strlen(haystack));
    printf("String after |%s| is - |%s|\n", needle, ret);
    return 0;
}
```
Bu programda, `strnstr` fonksiyonu ile bir karakter dizisinde belirli bir alt dizinin ilk kez geçtiği yer bulunur ve bulunan yerden sonraki dizi ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
String after |point| is - |point.com|
```
----------------------------------------------------------------------------------------------------------------------------------------------
`calloc` fonksiyonu, C dilinde belirli bir sayıda belirli boyutta bellek bloklarını ayrıp, bu blokları sıfır ile başlatmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `void *calloc(size_t num, size_t size)`. `num` parametresi, ayrılacak bellek bloklarının sayısını belirtir.
`size` parametresi ise her bir bellek bloğunun boyutunu belirtir.
Bu fonksiyon, `num * size` baytlık bir bellek bloğu ayırır ve bu bloğu sıfırlar.
Eğer bellek başarıyla ayrılırsa, bu fonksiyon ayrılan bellek bloğunun ilk baytını gösteren bir işaretçi döndürür. Eğer bellek ayrılamazsa, bu fonksiyon `NULL` döndürür.
Aşağıda, `calloc` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    int *ptr;
    int num = 5;
    ptr = (int*) calloc(num, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    for (int i = 0; i < num; i++) {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}
```
Bu programda, `calloc` fonksiyonu ile 5 adet `int` tipinde bellek bloğu ayrılır ve bu blokların içeriği ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
0 0 0 0 0
```
----------------------------------------------------------------------------------------------------------------------------------------------
`strdup` fonksiyonu, C dilinde bir karakter dizisinin kopyasını oluşturmak için kullanılır.
Bu fonksiyonun bildirimi şu şekildedir: `char *strdup(const char *s)`. `s` parametresi, kopyalanacak C dizisini gösterir.
Bu fonksiyon, `s` tarafından belirtilen karakter dizisinin kopyasını oluşturur.
Eğer bellek başarıyla ayrılırsa, bu fonksiyon ayrılan bellek bloğunun ilk baytını gösteren bir işaretçi döndürür. Eğer bellek ayrılamazsa, bu fonksiyon `NULL` döndürür.
Aşağıda, `strdup` fonksiyonunun basit bir kullanımını gösteren bir kod parçacığı bulunmaktadır:

int main(void) {
    char *str1 = "Hello World";
    char *str2;
    str2 = strdup(str1);
    printf("Original string: %s\n", str1);
    printf("Duplicate string: %s\n", str2);
    return 0;
}
```
Bu programda, `strdup` fonksiyonu ile bir karakter dizisinin kopyası oluşturulur ve kopyalanan dizi ekrana yazdırılır. Programın çıktısı şu şekildedir:
```
Original string: Hello World
Duplicate string: Hello World
```
----------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------
#include <unistd.h>