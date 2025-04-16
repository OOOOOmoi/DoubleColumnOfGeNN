#include "definitionsInternal.h"
#include "supportCode.h"

struct MergedSynapseDendriticDelayUpdateGroup0
 {
    unsigned int* denDelayPtr;
    
}
;
struct MergedPresynapticUpdateGroup0
 {
    float* denDelay;
    unsigned int* denDelayPtr;
    unsigned int* srcSpkCnt;
    unsigned int* srcSpk;
    unsigned int* rowLength;
    uint32_t* ind;
    scalar* g;
    uint8_t* d;
    unsigned int numSrcNeurons;
    unsigned int numTrgNeurons;
    unsigned int rowStride;
    
}
;
__device__ __constant__ MergedSynapseDendriticDelayUpdateGroup0 d_mergedSynapseDendriticDelayUpdateGroup0[424];
void pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(unsigned int idx, unsigned int* denDelayPtr) {
    MergedSynapseDendriticDelayUpdateGroup0 group = {denDelayPtr, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDendriticDelayUpdateGroup0, &group, sizeof(MergedSynapseDendriticDelayUpdateGroup0), idx * sizeof(MergedSynapseDendriticDelayUpdateGroup0)));
}
__device__ __constant__ MergedPresynapticUpdateGroup0 d_mergedPresynapticUpdateGroup0[424];
void pushMergedPresynapticUpdateGroup0ToDevice(unsigned int idx, float* denDelay, unsigned int* denDelayPtr, unsigned int* srcSpkCnt, unsigned int* srcSpk, unsigned int* rowLength, uint32_t* ind, scalar* g, uint8_t* d, unsigned int numSrcNeurons, unsigned int numTrgNeurons, unsigned int rowStride) {
    MergedPresynapticUpdateGroup0 group = {denDelay, denDelayPtr, srcSpkCnt, srcSpk, rowLength, ind, g, d, numSrcNeurons, numTrgNeurons, rowStride, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedPresynapticUpdateGroup0, &group, sizeof(MergedPresynapticUpdateGroup0), idx * sizeof(MergedPresynapticUpdateGroup0)));
}
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
__device__ __constant__ unsigned int d_mergedPresynapticUpdateGroupStartID0[] = {0, 1152, 1408, 1728, 1984, 2112, 2176, 2304, 2432, 2496, 2624, 2688, 2752, 2816, 2880, 2944, 3008, 3072, 3136, 3200, 3264, 3328, 3392, 3456, 3520, 4160, 5568, 5824, 5952, 6016, 6336, 6400, 6464, 6720, 6784, 6912, 7104, 7168, 7488, 7680, 8256, 8512, 8640, 8704, 8832, 8896, 8960, 9024, 9152, 9216, 9280, 9408, 9472, 9536, 9600, 9792, 10048, 10112, 10240, 10304, 10432, 10496, 10560, 11328, 11776, 11968, 12160, 12672, 12736, 12800, 12928, 15808, 16384, 16640, 16768, 17024, 17152, 17216, 17280, 17344, 17536, 17600, 18624, 21120, 21312, 21376, 21696, 21760, 21824, 21888, 21952, 22016, 22080, 22144, 24128, 24320, 24448, 24576, 24768, 24832, 24896, 24960, 25024, 25088, 25152, 25216, 27008, 29504, 30336, 31104, 31168, 31296, 31360, 31488, 31552, 31616, 34624, 35200, 35328, 35968, 36416, 36544, 36608, 36672, 37248, 37312, 38336, 40384, 40512, 40896, 40960, 41536, 41600, 41664, 41728, 41792, 41984, 42048, 43712, 44544, 45952, 46144, 46848, 46976, 47360, 47424, 47488, 47552, 47616, 47680, 47744, 47872, 47936, 48256, 49024, 49088, 49152, 49216, 49280, 49344, 49408, 50112, 50688, 50752, 50880, 51136, 51200, 51264, 51328, 52352, 54400, 54464, 54528, 54592, 54656, 54912, 54976, 55040, 55104, 55168, 55680, 56256, 56448, 56576, 56640, 56704, 56768, 57024, 57088, 57152, 57216, 57280, 57600, 58368, 58432, 58496, 58560, 58624, 58688, 58752, 58816, 58880, 58944, 59008, 59072, 59136, 59200, 59264, 59328, 59392, 59456, 59520, 59584, 61248, 61440, 61824, 62144, 62272, 62336, 62464, 62528, 62592, 62784, 62848, 64512, 66560, 67072, 67264, 67392, 67840, 67968, 68096, 68480, 68608, 68800, 68992, 69056, 69120, 69184, 69248, 69312, 69376, 69440, 69504, 69568, 69632, 69696, 69760, 69824, 69888, 70336, 70464, 71232, 71616, 71744, 71872, 72000, 72128, 72192, 72256, 72320, 72384, 72448, 72576, 72640, 72704, 72768, 72832, 72896, 72960, 73024, 73088, 73152, 73216, 73280, 73344, 73408, 73472, 73536, 73600, 73792, 74176, 74240, 74432, 74496, 74624, 74688, 74752, 76032, 76480, 76736, 76992, 77632, 77696, 77760, 77952, 82176, 82624, 82944, 83072, 83392, 83456, 83520, 83584, 83648, 83904, 83968, 86848, 90496, 90944, 91008, 91456, 91520, 91584, 91648, 91712, 91840, 91968, 92032, 94912, 95168, 95296, 95424, 95680, 95744, 95808, 95872, 95936, 96000, 96064, 96128, 98944, 100992, 102080, 103168, 103232, 103360, 103424, 103552, 103616, 103680, 108032, 108480, 108608, 109376, 109952, 110016, 110080, 110144, 110976, 111040, 113920, 116864, 117056, 117824, 117888, 118720, 118784, 118848, 118976, 119104, 119360, 119424, 122240, 123008, 124992, 125248, 126144, 126208, 126784, 126848, 126912, 126976, 127040, 127104, 127168, 127296, 127360, 127744, 128832, 128896, 129024, 129088, 129216, 129280, 129344, 130304, 130752, 130816, 130880, 131200, 131264, 131328, 131392, 134272, 137216, 137280, 137344, 137408, 137472, 137856, 137920, 138048, 138112, 138176, 138624, 139456, 139712, 139776, 139840, 139904, 139968, 140352, 140416, 140480, 140544, 140608, 140992, 142080, 142144, 142272, 142336, 142464, 142528, };
extern "C" __global__ void synapseDendriticDelayUpdateKernel() {
    const unsigned int id = 32 * blockIdx.x + threadIdx.x;
    // merged0
    if(id < 424) {
        struct MergedSynapseDendriticDelayUpdateGroup0 *group = &d_mergedSynapseDendriticDelayUpdateGroup0[id - 0]; 
        *group->denDelayPtr = (*group->denDelayPtr + 1) % 43;
    }
    
}

extern "C" __global__ void updatePresynapticKernel(float t)
 {
    const unsigned int id = 64 * blockIdx.x + threadIdx.x; 
    __shared__ unsigned int shRowLength[64];
    __shared__ unsigned int shSpk[64];
    // merged0
    if(id < 142592) {
        unsigned int lo = 0;
        unsigned int hi = 424;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedPresynapticUpdateGroupStartID0[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedPresynapticUpdateGroup0 *group = &d_mergedPresynapticUpdateGroup0[lo - 1]; 
        const unsigned int groupStartID = d_mergedPresynapticUpdateGroupStartID0[lo - 1];
        const unsigned int lid = id - groupStartID;
         {
            const unsigned int numSpikes = group->srcSpkCnt[0];
            const unsigned int numSpikeBlocks = (numSpikes + 64 - 1) / 64;
            for (unsigned int r = 0; r < numSpikeBlocks; r++) {
                const unsigned int numSpikesInBlock = (r == numSpikeBlocks - 1) ? ((numSpikes - 1) % 64) + 1 : 64;
                __syncthreads();
                if (threadIdx.x < numSpikesInBlock) {
                    const unsigned int spk = group->srcSpk[(r * 64) + threadIdx.x];
                    shSpk[threadIdx.x] = spk;
                    shRowLength[threadIdx.x] = group->rowLength[spk];
                }
                __syncthreads();
                // loop through all incoming spikes
                for (unsigned int j = 0; j < numSpikesInBlock; j++) {
                    // only work on existing neurons
                    if (lid < group->rowStride) {
                        const unsigned int synAddress = (shSpk[j] * group->rowStride) + lid;
                        const unsigned int npost = shRowLength[j];
                        if (lid < npost) {
                            const unsigned int ipost = group->ind[synAddress];
                            atomicAdd(&group->denDelay[(((*group->denDelayPtr + group->d[synAddress]) % 43) * group->numTrgNeurons) + ipost], group->g[synAddress]);
                        }
                    }
                }
            }
        }
        
    }
}
void updateSynapses(float t) {
     {
        const dim3 threads(32, 1);
        const dim3 grid(14, 1);
        synapseDendriticDelayUpdateKernel<<<grid, threads>>>();
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
    }
     {
        CHECK_CUDA_ERRORS(cudaEventRecord(presynapticUpdateStart));
        const dim3 threads(64, 1);
        const dim3 grid(2228, 1);
        updatePresynapticKernel<<<grid, threads>>>(t);
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
        CHECK_CUDA_ERRORS(cudaEventRecord(presynapticUpdateStop));
    }
}
