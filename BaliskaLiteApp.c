// project dibuat Rifqi Makarim
// BALISKA App
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct barang
{
    int nomor;
    char nama[60];
    double harga_kain;
    double harga_kemeja_SM;
    double harga_kemeja_LXL;
    int stok_kain;
    int stok_kemeja_SM;
    int stok_kemeja_LXL;
};

void peringatan();
void daftar_belanja(struct barang belanjaan[], int jumlah_belanja, double total_harga, int kemeja_anak, int kemeja_remaja, int kain);

int main()
{
    puts(".");
    puts("======================== SELAMAT DATANG DI BASLIKA =======================");
    puts("                Tempat Jual Online Batik Asli Pekalongan ");
    puts("--------------------------------------------------------------------------");

    int username;
    double TotalHarga = 0;
    int jumlah_belanja = 0;
    int kemeja_anak = 0, kemeja_remaja = 0, kain = 0;
    int beli_lagi;

    puts("Silakan Ketik ID Username Anda [Hanya Berupa Angka]");
    printf("Username       : ");
    scanf("%d", &username);

    struct barang daftar_barang[6];
    struct barang belanjaan[6];

    daftar_barang[0].nomor = 1;
    strcpy(daftar_barang[0].nama, "Batik Motif Semen");
    daftar_barang[0].harga_kain = 250000;
    daftar_barang[0].harga_kemeja_SM = 75000;
    daftar_barang[0].harga_kemeja_LXL = 100000;

    daftar_barang[1].nomor = 2;
    strcpy(daftar_barang[1].nama, "Batik Motif Terang Bulan");
    daftar_barang[1].harga_kain = 200000;
    daftar_barang[1].harga_kemeja_SM = 85000;
    daftar_barang[1].harga_kemeja_LXL = 115000;

    daftar_barang[2].nomor = 3;
    strcpy(daftar_barang[2].nama, "Batik Motif Jlamprang");
    daftar_barang[2].harga_kain = 125000;
    daftar_barang[2].harga_kemeja_SM = 85000;
    daftar_barang[2].harga_kemeja_LXL = 105000;

    daftar_barang[3].nomor = 4;
    strcpy(daftar_barang[3].nama, "Batik Liong");
    daftar_barang[3].harga_kain = 121000;
    daftar_barang[3].harga_kemeja_SM = 81000;
    daftar_barang[3].harga_kemeja_LXL = 102000;

    daftar_barang[4].nomor = 5;
    strcpy(daftar_barang[4].nama, "Batik Motif Sawat");
    daftar_barang[4].harga_kain = 130000;
    daftar_barang[4].harga_kemeja_SM = 89000;
    daftar_barang[4].harga_kemeja_LXL = 121000;

    daftar_barang[5].nomor = 6;
    strcpy(daftar_barang[5].nama, "Batik Jawa Hokokai");
    daftar_barang[5].harga_kain = 200000;
    daftar_barang[5].harga_kemeja_SM = 90000;
    daftar_barang[5].harga_kemeja_LXL = 150000;

    do
    {
        puts("============================= DAFTAR BARANG ============================");
        puts("SEDIA : ");

        for (int i = 0; i < 6; i++)
        {
            printf("%-5d %-26s\n", daftar_barang[i].nomor, daftar_barang[i].nama);
        }
        puts("------------------------------------------------------------------------");

        int pilihan_barang;
        do
        {
            printf("Pilih Nomor Barang Yang Mau Dibeli : ");
            scanf("%d", &pilihan_barang);
            if (pilihan_barang < 1 || pilihan_barang > 6)
            {
                peringatan();
            }
        } while (pilihan_barang < 1 || pilihan_barang > 6);

        int indeks = pilihan_barang - 1;
        puts("--------------------------------------------------------------------");

        printf("JENIS BARANG :\n\n");
        printf("(1) Kemeja %s\n", daftar_barang[indeks].nama);
        printf("(2) Kain %s\n", daftar_barang[indeks].nama);

        int pilihan_jenisbarang;
        do
        {
            printf("\nPILIH JENIS BARANG : ");
            scanf("%d", &pilihan_jenisbarang);
            if (pilihan_jenisbarang < 1 || pilihan_jenisbarang > 2)
            {
                peringatan();
            }
        } while (pilihan_jenisbarang < 1 || pilihan_jenisbarang > 2);

        puts("--------------------------------------------------------------------------");
        if (pilihan_jenisbarang == 1)
        {
            puts("PILIH UKURAN KEMEJA");
            printf("(1) Ukuran Anak   - Harga : Rp. %.2f\n", daftar_barang[indeks].harga_kemeja_SM);
            printf("(2) Ukuran Remaja - Harga : Rp. %.2f\n", daftar_barang[indeks].harga_kemeja_LXL);

            int pilih_ukuran;
            do
            {
                printf("Pilih Ukuran (1 atau 2) : ");
                scanf("%d", &pilih_ukuran);
                if (pilih_ukuran < 1 || pilih_ukuran > 2)
                {
                    peringatan();
                }
            } while (pilih_ukuran < 1 || pilih_ukuran > 2);
            if (pilih_ukuran == 1)
            {
                kemeja_anak++;
            }
            else if (pilih_ukuran == 2)
            {
                kemeja_remaja++;
            }
            else
            {
                printf("");
            }
        }
        else if (pilihan_jenisbarang == 2)
        {
            printf("Ukuran Batik : 2 meter x 2 meter\n");
            printf("Harga        : Rp.%.2f\n", daftar_barang[indeks].harga_kain);
            kain++;
        }
        else
        {
            printf("INVALID");
        }

        // printf("KERANJANG BELANJA\n");

        belanjaan[jumlah_belanja] = daftar_barang[indeks];
        jumlah_belanja++;

        do
        {
            puts("--------------------------------------------------------------------------");
            puts("\nAPAKAH ANDA MAU MEMBELI BARANG LAGI ?");
            puts("1 = YA dan 0 = TIDAK");
            scanf("%d", &beli_lagi);
            puts("--------------------------------------------------------------------------");
            if (beli_lagi == 0)
            {
                daftar_belanja(belanjaan, jumlah_belanja, TotalHarga, kemeja_anak, kemeja_remaja, kain);

                puts("--------------------------------------------------------------------------");
                puts("              TERIMAKASIH SUDAH MEMBELI BARANG DI BALISKA");
                puts("--------------------------------------------------------------------------");
            }
            else if (beli_lagi == 1)
            {
                printf("\nLOADING . . .\n");
            }
            else
            {
                peringatan();
            }
        } while (beli_lagi != 0 && beli_lagi != 1);
    } while (beli_lagi == 1);

    //
}

void peringatan()
{
    puts("[INVALID] Nomor yang Anda Masukkan Tidak Valid");
    puts("Silakan Masukkan Kembali dengan Nomor yang Benar\n");
}

void daftar_belanja(struct barang belanjaan[], int jumlah_belanja, double total_harga, int kemeja_anak, int kemeja_remaja, int kain)
{
    puts("============================= DAFTAR BELANJA =============================");
    srand(time(NULL));
    int kode = rand() % 10000001;
    printf("Kode Pesanan : GBATIK10%d\n\n", kode);

    if (jumlah_belanja == 0)
    {
        puts("TIDAK ADA BARANG YANG DIBELI");
        printf("\nTOTAL HARGA PEMBELIAN : Rp.%.2f\n", total_harga);
        return;
    }

    printf("%-26s %8s %13s\n", "NAMA BARANG", "HARGA", "JENIS");

    for (int i = 0; i < jumlah_belanja; i++)
    {
        if (kain > 0)
        {
            printf("%-26s Rp.%-12.2f   KAIN\n", belanjaan[i].nama, belanjaan[i].harga_kain);
            total_harga += belanjaan[i].harga_kain;
            kain--;
        }
        else if (kemeja_anak > 0)
        {
            printf("%-26s Rp.%-12.2f KEMEJA Anak\n", belanjaan[i].nama, belanjaan[i].harga_kemeja_SM);
            total_harga += belanjaan[i].harga_kemeja_SM;
            kemeja_anak--;
        }
        else
        {
            printf("%-26s Rp.%-12.2f KEMEJA Remaja\n", belanjaan[i].nama, belanjaan[i].harga_kemeja_LXL);
            total_harga += belanjaan[i].harga_kemeja_LXL;
            kemeja_remaja--;
        }
    }

    puts("--------------------------------------------------------------------------");
    printf("TOTAL HARGA PEMBELIAN     : Rp.%.2f\n", total_harga);
    puts("--------------------------------------------------------------------------");
    printf("\n");

    int diskon[] = {20, 30, 40};
    if (total_harga >= 500000)
    {
        puts("--------------------------------------------------------------------------");
        puts("SELAMAT ANDA MENDAPAT DISKON");
        srand(time(0));
        int d = rand() % 3;
        printf("DISKON ANDA : %d%%\n", diskon[d]);
        int harga_akhir = total_harga - (total_harga * diskon[d] / 100);
        printf("HARGA AKHIR PEMBELIAN ANDA : Rp.%d.00\n", harga_akhir);
        total_harga = harga_akhir;
        puts("--------------------------------------------------------------------------");
    }

    int bayar;
    double uang, kembalian;
    int kartu_kredit[10];

    do
    {
        puts("PILIH METODE PEMBAYARAN");
        printf("[1] CASH\n[2] KARTU KREDIT\n");
        printf("PILIH : ");
        scanf("%d", &bayar);
        if (bayar < 1 || bayar > 2)
        {
            peringatan();
        }
    } while (bayar < 1 || bayar > 2);

    switch (bayar)
    {
    case 1:
        printf("Silakan Masukkan Uang Anda : Rp.");
        scanf("%lf", &uang);
        if (uang < total_harga)
        {
            printf("PERHATIAN : ISIKAN UANG ANDA DENGAN MELEBIHI ATAU PAS DARI PEMBELIAN\n");
            printf("Silakan Masukkan Kembali Uang Anda : Rp.");
            uang = 0;
            scanf("%lf", &uang);
            kembalian = uang - total_harga;
            printf("Kembalian : Rp.%.2f\n", kembalian);
        }
        else if (uang > total_harga)
        {
            kembalian = uang - total_harga;
            printf("Kembalian : Rp.%.2f\n", kembalian);
        }
        break;

    case 2:
        printf("Silakan Masukkan Kartu Kredit Anda : \n");
        scanf("%d", &kartu_kredit);
        printf("Silakan Masukkan Uang Anda : Rp.");
        scanf("%lf", &uang);
        if (uang < total_harga)
        {
            printf("PERHATIAN : ISIKAN UANG ANDA DENGAN MELEBIHI ATAU PAS DARI PEMBELIAN\n");
            printf("Silakan Masukkan Kembali Uang Anda : Rp.");
            uang = 0;
            scanf("%lf", &uang);
            kembalian = uang - total_harga;
            printf("Kembalian : Rp.%.2f\n", kembalian);
        }
        else if (uang >= total_harga)
        {
            kembalian = uang - total_harga;
            printf("Kembalian : Rp.%.2f\n", kembalian);

            printf("PEMBAYARAN BERHASIL DENGAN KARTU KREDIT\n");
        }
        break;
    }
}
