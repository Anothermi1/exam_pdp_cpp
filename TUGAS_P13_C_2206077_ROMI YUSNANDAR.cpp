#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool checkExist(vector<int> arr, int cari){
    for(int i=0; i< arr.size(); i++){
        if(arr[i]==cari) return true;
    }
    return false;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void binary_search(vector<int>& arr, int cari)
{
    int kiri = 0;
    int kanan = arr.size() - 1;
    bool ketemu = false;

    while (kiri <= kanan)
    {
        int tengah = (kiri + kanan) / 2;
        if (arr[tengah] == cari)
        {
            cout<<cari<<" sudah di tambahkan, ditemukan di index: "<<tengah<<endl;
            ketemu = true;
            break;
        }
        else if (arr[tengah] < cari)
        {
            kiri = tengah + 1;
        }
        else
        {
            kanan = tengah - 1;
        }
    }
    if (!ketemu)
    {
        cout<<"Array saat ini: "<<endl;
    }
}

int main()
{
    int arr[] = {1, 3, 5};
    int ukuran = sizeof(arr) / sizeof(arr[0]);
    int cari;
    string tanya;
    vector<int> new_arr(arr, arr + ukuran);

    cout<<"Nilai saat ini :";
    for_each(new_arr.begin(), new_arr.end(), [](int x)
    {
        cout<<x<<" ";
    });
    cout<<endl;
    cout<<"\nIngin menambahkan niali? y/n: "; cin>>tanya;
    while (tanya == "y")
    {
        cout<<"\nMasukan Angka: "; cin>>cari;
        if(checkExist(new_arr, cari)){
            cout<<cari<<" sudah ada, masukan angka lain"<<endl;
        }else{
            new_arr.push_back(cari); // tambah nilai inputan ke array
            // sorting array dengan insertion sort
            insertionSort(new_arr);
            // cek data baru dengan binary search
            binary_search(new_arr, cari);
            // print array yang sudah ditambahkan nilai
            for_each(new_arr.begin(), new_arr.end(), [](int x)
            {
                cout<<x<<" ";
            });
            cout<<endl;
            cout<<"\nIngin menambahkan niali? y/n: "; cin>>tanya;
        }
    }if (tanya == "n")
    {
    	cout<<"\nNilai Akhir: ";
    	for_each(new_arr.begin(), new_arr.end(), [](int x)
		{
			cout<<x<<" ";
		});
	} else
	{
		cout<<"\nNilai Akhir: ";
    	for_each(new_arr.begin(), new_arr.end(), [](int x)
		{
			cout<<x<<" ";
		});
	}
}
