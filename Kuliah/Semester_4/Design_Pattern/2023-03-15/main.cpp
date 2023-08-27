#include <iostream>

#pragma region InterfaceCargo
class InterfaceCargo
{
public:
    InterfaceCargo()
    {
        return;
    }
};

class CargoLiquid : public InterfaceCargo
{
public:
    CargoLiquid()
    {
        std::cout << "Cargo Liquid Selesai\n";
    }
};

class CargoGas : public InterfaceCargo
{
public:
    CargoGas()
    {
        std::cout << "Cargo Gas Selesai\n";
    }
};

class CargoSolid : public InterfaceCargo
{
public:
    CargoSolid()
    {
        std::cout << "Cargo Solid Selesai\n";
    }
};
#pragma endregion


#pragma region CargoFactory
class InterfaceCargoFactory
{
public:
    virtual InterfaceCargo *MakeCargo() = 0;
};

class CargoLiquidFactory : public InterfaceCargoFactory
{
    InterfaceCargo *MakeCargo() override
    {
        std::cout << "Membuat Cargo Liquid\n";
        return new CargoLiquid();
    }
};

class CargoGasFactory : public InterfaceCargoFactory
{
    InterfaceCargo *MakeCargo() override
    {
        std::cout << "Membuat Cargo Gas\n";
        return new CargoGas();
    }
};

class CargoSolidFactory : public InterfaceCargoFactory
{
    InterfaceCargo *MakeCargo() override
    {
        std::cout << "Membuat Cargo Solid\n";
        return new CargoSolid();
    }
};
#pragma endregion


#pragma region transport
class InterfaceTransport
{
public:
    InterfaceCargo *currentCargo;
    virtual void MakeTransport(InterfaceCargo *cargo) = 0;
};

class TransportAir : public InterfaceTransport
{
public:
    void MakeTransport(InterfaceCargo *cargo) override
    {
        currentCargo = cargo;
        std::cout << "Melakukan transportasi jalur udara!\n";
    }
};

class TransportLand : public InterfaceTransport
{
public:
    void MakeTransport(InterfaceCargo *cargo) override
    {
        currentCargo = cargo;
        std::cout << "Melakukan transportasi jalur darat!\n";
    }
};

class TransportSea : public InterfaceTransport
{
public:
    void MakeTransport(InterfaceCargo *cargo) override
    {
        currentCargo = cargo;
        std::cout << "Melakukan transportasi jalur laut!\n";
    }
};
#pragma endregion


#pragma region factory
class CargoFactory
{
public:
    InterfaceCargoFactory *createCargoFactory;
    InterfaceTransport *createTransport;
};
#pragma endregion


int main()
{
    //Factory Muncul
    CargoFactory* factory = new CargoFactory();

    /*
    Kasus: 
       - Client meminta cargo bertipe liquid
       - Client meminta pengiriman cargo lewat darat
    */

    //Pabrik membuat cargo bertipe liquid
    factory->createCargoFactory = new CargoLiquidFactory();
    
    //Pabrik menyiapkan pengiriman cargo menggunakan jalur darat
    factory->createTransport = new TransportLand();
    
    //Pengiriman dilakukan dengan memasukkan cargo yang telah jadi ke dalam transport, lalu melakukan transport
    factory->createTransport->MakeTransport(factory->createCargoFactory->MakeCargo()); 


    delete factory;
    
    return 0;
}

