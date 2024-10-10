#include <iostream>
#include <vector>

using namespace std;

struct Account {
	string username;
	string password;
};

bool logout() {
	return false;
}

bool login(string username, string password, const vector<Account> accounts) {
	for (const Account account : accounts) {
		if (username == account.username && password == account.password) {
			cout << "Login Berhasil!, Selamat datang " << username << endl;
			return true;
		}
	}
	cout << "Username/Password Salah" << endl;
	return false;
}

void registerAccount(string username, string password, vector<Account> verif) {
	for (const Account account : verif) {
		if (username == account.username) {
			cout << "Registrasi Gagal, Akun sudah terdaftar." << endl;
			return;
		}
	}
	verif.push_back({username, password});
	cout << "Registrasi Sukses!, Mohon tunggu sampai akun di verifikasi oleh Admin! " << endl;
}

int main() {
	vector<Account> accounts = {{"admin", "admin123"}};
	vector<Account> verif = {};
	int pulpen=10, pensil=10, penggaris=10, penghapus=10; 
	string username, password;
	string regUsername, regPassword;
	bool isLogged = false;
	int n;

	while (true) {
		cout << "========== KeKasir ==========" << endl;
		cout << "1. Register" << endl << "2. Login" << endl << "3. Exit" << endl;
		cin >> n;

		if (n == 1) {
			cout << "==Register==" << endl << "Username: ";
			cin >> regUsername;
			cout << "Password: ";
			cin >> regPassword;
			registerAccount(regUsername, regPassword, verif);
		} else if (n == 2) {
			while (!isLogged) {
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
				isLogged = login(username, password, accounts);
			}
		} else if (n == 3) {
			cout << "Menutup Program.. Mohon Tunggu" << endl;
			break;
		} else {
			cout << "Pilihan tidak valid." << endl;
		}

		while (isLogged) {
			while (true) {
				int input;
				cout << "========================================" << endl;
				cout << "User: " << username << endl;
				cout << "9: Log Out" << endl;
				cout << "8. Verifikasi Akun";
				if(verif.size()  > 0) {
					cout << endl;
					cout << "(Terdapat "<< verif.size() << " " << "akun menunggu Verifikasi)" << endl;
				} else {
					cout << endl;
				}
				cout << "========================================" << endl;
				cout << "1.Kasir" << endl;
				cout << "2.Inventaris" << endl;
				cin >> input;
				if(input == 1) {
					while(true) {
					    	int pulpenK=0, pensilK=0, penggarisK=0, penghapusK=0;
        					int Jumlah_uang=0, Total_harga=0, Kembalian=0;
        					int input1, input2;
						while(true) {
							cout << "Stok tersedia: Pulpen (" << pulpen << "), Pensil (" << pensil << "), Penggaris (" << penggaris << "), Penghapus (" << penghapus << ")" << endl;
							cout << "\nBarang yang sedang dibeli:" << endl;
							if(pulpenK > 0) cout << "Pulpen : " << pulpenK << endl;
							if(pensilK > 0) cout << "Pensil : " << pensilK << endl;
							if(penggarisK > 0) cout << "Penggaris : " << penggarisK << endl;
							if(penghapusK > 0) cout << "Penghapus : " << penghapusK << endl;
							cout << "Masukkan barang yang dibeli " << endl;
							cout << "1 . Pulpen" << endl << "2 . Pensil" << endl << "3 . Penggaris" << endl << "4 . Penghapus" << endl << "8. Lanjut Ke Kasir" << endl;
							cin >> input1;

							if(input1 == 8) {
								break;
							}

							cout << "Masukkan jumlah barang yang dibeli: ";
							cin >> input2;

							if(input1 == 1 && input2 <= pulpen) {
								pulpenK += input2;
								pulpen -= input2;
							} else if(input1 == 2 && input2 <= pensil) {
								pensilK += input2;
								pensil -= input2;
							} else if(input1 == 3 && input2 <= penggaris) {
								penggarisK += input2;
								penggaris -= input2;
							} else if(input1 == 4 && input2 <= penghapus) {
								penghapusK += input2;
								penghapus -= input2;
							} else {
								cout << "Stok tidak cukup atau barang tidak tersedia!" << endl;
							}
						}

						int harga_pulpen = 3000 * pulpenK;
						int harga_pensil = 1000 * pensilK;
						int harga_penggaris = 3000 * penggarisK;
						int harga_penghapus = 1500 * penghapusK;

						Total_harga = harga_pulpen + harga_pensil + harga_penggaris + harga_penghapus;
						cout << "Total harga : " << Total_harga << endl;
						cout << "Masukkan nominal uang yang diberikan: ";
						cin >> Jumlah_uang;

						if(Jumlah_uang >= Total_harga) {
							Kembalian = Jumlah_uang - Total_harga;
							cout << "========== STRUK ==========" << endl;
							if(pulpenK > 0) cout << "Pulpen : " << pulpenK << endl;
							if(pensilK > 0) cout << "Pensil : " << pensilK << endl;
							if(penggarisK > 0) cout << "Penggaris : " << penggarisK << endl;
							if(penghapusK > 0) cout << "Penghapus : " << penghapusK << endl;
							cout << "============================" << endl;
							cout << "Pembayaran: " << Jumlah_uang << endl;
							cout << "Total Harga: " << Total_harga << endl;
							cout << "Kembalian: " << Kembalian << endl;
						} else {
							cout << "Uang tidak cukup!" << endl;
							pulpen += pulpenK;
							pensil += pensilK;
							penggaris += penggarisK;
							penghapus += penghapusK;
						}
						cout << "Lanjut atau kembali? [y/n]" << endl;
						char choice;
						cin >> choice;
						if(choice == 'n') {
							break;
						}
					}
				}
				if(input == 2) {
					while (true) {

						int input1, input2;
						cout << "Barang Apa yang Ingin Anda Tambah? " << endl;
						cout << "1. Pulpen ("<< pulpen << ")" << endl << "2. Pensil (" << pensil << ")" << endl << "3. Penggaris (" << penggaris <<")" << endl << "4.Penghapus ("<< penghapus << ")" << endl  << "9. Cancel" << endl;
						cin >> input1;

						if(input1 == 1) {
							cout << "Pulpen\n" << endl;
							cout << "Berapa Jumlah Stok yang Akan ditambah? " << endl;
							cin >> input2;
							pulpen = pulpen+input2;
							cout << "Total Pulpen Adalah : " << pulpen << endl << endl;

						} else if(input1 == 2) {
							cout << "Pensil\n" << endl;
							cout << "Berapa Jumlah Stok yang Akan ditambah? " << endl;
							cin >> input2;
							pensil = pensil+input2;
							cout << "Total Pensil Adalah : " << pensil << endl << endl;

						} else if(input1 == 3) {
							cout << "Penggaris\n" << endl;
							cout << "Berapa Jumlah Stok yang Akan ditambah? " << endl;
							cin >> input2;
							penggaris = penggaris + input2;
							cout << "Total Penggaris Adalah : \n" << penggaris << endl;

						} else if(input1 == 9) {
							break;
						} else{
						    cout << "Option Tidak Valid!" << endl;
						}
					}
				}
				if (input == 9) {
					char confirm;
					cout << "Apa kau yakin ingin Logout? (y/n): ";
					cin >> confirm;
					if (confirm == 'y') {
						isLogged = logout();
					}
				}
				else{
				    cout << "Pilihan tidak valid." << endl;
				}
			}
		}
	}

	return 0;
}
