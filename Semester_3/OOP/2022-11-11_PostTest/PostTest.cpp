#include <iostream>
#include <vector>

class BasicTicket
{
protected:
    std::string nama_penumpang;
    std::string kota_keberangkatan;
    std::string kota_kedatangan;
    std::string nomor_penerbangan;
    int harga_tiket;

public:
    BasicTicket(std::string nama_penumpang, std::string kota_keberangkatan,
    std::string kota_kedatangan,
    std::string nomor_penerbangan,
    int harga_tiket)
    {
        this->nama_penumpang = nama_penumpang;
        this->kota_keberangkatan = kota_keberangkatan;
        this->kota_kedatangan = kota_kedatangan;
        this->nomor_penerbangan = nomor_penerbangan;
        this->harga_tiket = harga_tiket;
    }

    BasicTicket()
    {
        harga_tiket = 0;
    }

    int getPrice()
    {
        return this->harga_tiket;
    }

    double operator+(BasicTicket b)
    {
        return this->getPrice() + b.getPrice(); 
    }

    void operator=(double sum)
    {
        this->harga_tiket = sum;
    }

    friend std::ostream& operator<<(std::ostream& out, const BasicTicket& aTicket)
    {
    out << aTicket.harga_tiket << std::endl;
    return out;
    }
};


class PremiumTicket: public BasicTicket
{
protected:
    std::string nomor_penumpang;

public:
    PremiumTicket(std::string nomor_penumpang): BasicTicket("budi", "bali", "surabaya", "b001", 200000)
    {
        //this->nama_penumpang = nama_penumpang;
        //this->kota_keberangkatan = kota_keberangkatan;
        //this->kota_kedatangan = kota_kedatangan;
        //this->nomor_penerbangan = nomor_penerbangan;
        //this->harga_tiket = harga_tiket;
        this->nomor_penumpang = nomor_penumpang;
        setHargaPremiumTicket();
    }

    void setHargaPremiumTicket()
    {
        harga_tiket = harga_tiket + (harga_tiket * 10/100);
    }

    double operator+(BasicTicket b)
    {
        return this->getPrice() + b.getPrice(); 
    }
};

int main(int argc, const char** argv) 
{
    std::vector<BasicTicket> *b = new std::vector<BasicTicket>(4);
    
    BasicTicket basic1("adi", "bali", "surabaya", "b001", 200000);
    BasicTicket basic2("suki", "jakarta", "surabaya", "j001", 150000);
    
    b->push_back(basic1);
    b->push_back(basic2);

    //std::vector<PremiumTicket> *p = new std::vector<PremiumTicket>(3);

    PremiumTicket premium1("p001");
    PremiumTicket premium2("p002");

    b->push_back(premium1);
    b->push_back(premium2);


    std::cout << "harga basic ticket: "<< basic1.getPrice();

    std::cout << std::endl;

    std::cout << "harga premium ticket: "<< premium1.getPrice();
    
    std::cout << std::endl;

    std::cout << "total harga kedua tiket diatas adalah: " << basic1.getPrice() + premium1.getPrice();

    std::cout << std::endl;

    std::cout << "total harga dari vector Basic Ticket adalah: ";

    BasicTicket sum;
    for(int i = 0; i < b->size(); i++)
    {
        sum = sum + b->at(i);
    }

    std::cout << sum;
    
    return 0;
}