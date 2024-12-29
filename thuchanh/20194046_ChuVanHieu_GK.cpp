#include <bits/stdc++.h>

using namespace std;

struct Land {
    string id;
    double unitPrice;
    double area;
    double totalPrice;
    double deposit;
    double discount;

    Land(string id, double unitPrice) : id(id), unitPrice(unitPrice), area(0), totalPrice(0), deposit(0), discount(0) {}

    virtual void input() = 0;
    virtual void calculateArea() = 0;
    virtual void calculateTotalPrice() {
        totalPrice = area * unitPrice;
    }
    virtual void calculateDeposit() {
        if (id == "MD001") deposit = totalPrice * 0.7;
        else if (id == "MD002") deposit = totalPrice * 0.5;
        else if (id == "MD003") deposit = totalPrice * 0.3;
    }
    virtual void calculateDiscount() {
        if (id == "MD001" || id == "MD002") discount = totalPrice * 0.1;
    }

    void display() {
        cout << "ID: " << id << ", Area: " << area << ", Total Price: " << totalPrice << ", Deposit: " << deposit << ", Discount: " << discount << endl;
    }

    double getArea() { return area; }
    double getTotalPrice() { return totalPrice; }
    double getDiscount() { return discount; }
};

struct RectangleLand : public Land {
    double length;
    double width;

    RectangleLand(string id, double unitPrice) : Land(id, unitPrice), length(0), width(0) {}

    void input() override {
        cout << "\t\tNhap chieu dai va chieu rong: ";
        cin >> length >> width;
    }

    void calculateArea() override {
        area = length * width;
    }
};

struct TrapezoidLand : public Land {
    double base1;
    double base2;
    double height;

    TrapezoidLand(string id, double unitPrice) : Land(id, unitPrice), base1(0), base2(0), height(0) {}

    void input() override {
        cout << "\t\tNhap day nho, day lon va chieu cao: ";
        cin >> base1 >> base2 >> height;
    }

    void calculateArea() override {
        area = (base1 + base2) * height / 2;
    }
};

struct SquareLand : public Land {
    double side;

    SquareLand(string id, double unitPrice) : Land(id, unitPrice), side(0) {}

    void input() override {
        cout << "\t\t\tNhap canh hinh vuong: ";
        cin >> side;
    }

    void calculateArea() override {
        area = side * side;
    }
};

struct TriangleLand : public Land {
    double base;
    double height;

    TriangleLand(string id, double unitPrice) : Land(id, unitPrice), base(0), height(0) {}

    void input() override {
        cout << "Nhap day va chieu cao: ";
        cin >> base >> height;
    }

    void calculateArea() override {
        area = (base * height) / 2;
    }
};

struct Company {
    string name;
    string address;
    vector<Land*> lands;

    Company(string name, string address) : name(name), address(address) {}

    void addLand(Land* land) {
        lands.push_back(land);
    }

    void inputLands(int numLands) {
        for (int i = 0; i < numLands; ++i) {
            string id, shape;
            cout << "\t\tMa mieng dat thu (MD001, MD002, MD003,) " << i + 1 << ": ";
            cin >> id;
            cout << "\t\t\tMieng dat hinh (Vuong, Thang, Tam giac, HCNhat): ";
            cin >> shape;
            Land* land = nullptr;
            if (shape == "Vuong") {
                land = new SquareLand(id, (id == "MD001" ? 50 : (id == "MD002" ? 30 : 10)));
            } else if (shape == "Thang") {
                land = new TrapezoidLand(id, (id == "MD001" ? 50 : (id == "MD002" ? 30 : 10)));
            } else if (shape == "Tam giac") {
                land = new TriangleLand(id, (id == "MD001" ? 50 : (id == "MD002" ? 30 : 10)));
            } else if (shape == "HCNhat") {
                land = new RectangleLand(id, (id == "MD001" ? 50 : (id == "MD002" ? 30 : 10)));
            }
            if (land) {
                land->input();
                land->calculateArea();
                land->calculateTotalPrice();
                land->calculateDeposit();
                land->calculateDiscount();
                addLand(land);
                // Hiển thị thông tin ngay sau khi nhập
                cout << "\t\t\tDien tich: " << land->getArea() << endl;
                cout << "\t\t\tThanh tien: " << land->getTotalPrice() << endl;
                cout << "\t\t\tTien dat coc: " << land->getTotalPrice() * (id == "MD001" ? 0.7 : (id == "MD002" ? 0.5 : 0.3)) << endl;
                cout << "\t\t\tGiam gia: " << land->getDiscount() << endl;
            }
        }
    }

    void displayLands() {
        double totalArea = 0;
        double totalPrice = 0;
        double totalDiscount = 0;
        cout << "Cong ty: " << name << ", Dia chi: " << address << endl;
        for (Land* land : lands) {
            land->display();
            totalArea += land->getArea();
            totalPrice += land->getTotalPrice();
            totalDiscount += land->getDiscount();
        }
        cout << "Tong dien tich: " << totalArea << ", Tong thanh tien: " << totalPrice << ", Tong giam gia: " << totalDiscount << endl;
    }
};

vector<Company> companies;

void input(int n) {
    for (int i = 0; i < n; ++i) {
        string name, address;
        int numLands;
        cout << "Nhap thong tin cong ty " << i + 1 << ":" << endl;
        cout << "\tTen cong ty: ";
        cin.ignore();
        getline(cin, name);
        cout << "\tDia chi cong ty: ";
        getline(cin, address);
        cout << "\tSo mieng dat: ";
        cin >> numLands;
        Company company(name, address);
        company.inputLands(numLands);
        companies.push_back(company);
    }
}

void output() {
    cout << "Ban da chon in ra mieng dat!" << endl;
    for (Company& company : companies) {
        company.displayLands();
    }
}

void thoat() {
    cout << "Ban da chon thoat chuong trinh!" << endl;
    exit(0);
}

int main() {
    while (true) {
        cout << "** CHUONG TRINH QUAN LY BAT DONG SAN **" << endl;
        cout << "** 1. Nhap THONG TIN CONG TY         **" << endl;
        cout << "** 2. IN KET QUA DIEN TICH MIENG DAT **" << endl;
        cout << "** 0. Thoat                          **" << endl;
        cout << "***************************************" << endl;
        cout << "**     Nhap lua chon cua ban         **" << endl;

        int h;
        cin >> h;

        switch (h) {
            case 1: {
                int n;
                cout << "Nhap so luong cong ty: ";
                cin >> n;
                input(n);
                break;
            }
            case 2:
                output();
                break;
            case 0:
                thoat();
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    }

    return 0;
}