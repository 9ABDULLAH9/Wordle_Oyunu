# Kelime Tahmin Oyunu

Bu proje, kullanıcının belirlediği bir kelimeyi tahmin etmeye çalışan bir C dilinde yazılmış bir konsol uygulamasıdır.

## Projenin Amacı

Bu proje, C dilinde programlama becerilerini geliştirmek ve temel algoritmaları uygulamak amacıyla oluşturulmuştur. Ayrıca, kullanıcıların eğlenmesi ve kelime dağarcıklarını genişletmeleri için bir araç olarak da kullanılabilir.

## Başlarken

### Önkoşullar

Bu projeyi derlemek ve çalıştırmak için GCC derleyicisine ihtiyacınız olacak. Eğer sisteminizde yüklü değilse, aşağıdaki komutları kullanarak yükleyebilirsiniz:

```bash
sudo apt update
sudo apt install build-essential

Derleme
Proje dosyalarını derlemek için aşağıdaki komutları kullanabilirsiniz:

gcc -o game main.c function.c

Bu komut, main.c ve function.c dosyalarını derler ve çıktıyı game adlı bir dosyada saklar.

Kullanım
Derleme işlemi tamamlandıktan sonra, oyunu aşağıdaki komutla başlatabilirsiniz:

./game

Oyun, tahmin etmeniz gereken kelimeyi girmenizi isteyecektir. Daha sonra, kelimenin harflerini tahmin etmeye çalışacaksınız. Her tahmininizde, doğru ve yanlış yerdeki harfler ile olmayan harfler hakkında ipuçları alacaksınız.
