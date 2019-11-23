if [ ! -d cmake-main-build ]
then
    mkdir cmake-main-build
fi
cd cmake-main-build

cmake ../
make
./Checkout

cd ..

