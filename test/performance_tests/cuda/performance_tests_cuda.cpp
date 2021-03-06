#include <iostream>
#include "performance_test_image_function_cuda.h"
#include "../performance_test_framework.h"
#include "../performance_test_helper.h"
#include "../../../src/cuda/cuda_device.cuh"
#include "../../../src/cuda/cuda_helper.cuh"

int main( int argc, char * argv[] )
{
    if( !multiCuda::isCudaSupported() ) {
        std::cout << "No CUDA devices in the system" << std::endl;
        return 0;
    }

    Performance_Test::setRunCount( argc, argv, 128 );

    multiCuda::CudaDeviceManager & deviceManager = multiCuda::CudaDeviceManager::instance();
    deviceManager.initializeDevices();

    for ( int deviceId = 0; deviceId < deviceManager.deviceCount(); ++deviceId ) {
        deviceManager.setActiveDevice( deviceId );

        const multiCuda::CudaDevice & device = deviceManager.device();
        std::cout << device.name() << ": " << device.computeCapability() << std::endl;

        multiCuda::MemoryManager::memory().reserve( 32 * 1024 * 1024 ); // preallocate memory (32 MB)

        PerformanceTestFramework framework;
        addTests_Image_Function_Cuda( framework );

        framework.run();
    }

    return 0;
}
