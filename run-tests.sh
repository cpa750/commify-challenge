if [ ! -d cmake-test-build ]
then
    mkdir cmake-test-build
fi
cd cmake-test-build

cmake ../test/
make
./Tests

cd ..

