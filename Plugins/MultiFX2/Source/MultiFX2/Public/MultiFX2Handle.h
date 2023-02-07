#pragma once
#include "CoreMinimal.h"
#include "MultiFX2Handle.generated.h"

USTRUCT(BlueprintType)
struct FMultiFX2Handle {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint64 Handle;
    
public:
    MULTIFX2_API FMultiFX2Handle();
};
FORCEINLINE uint32 GetTypeHash(const FMultiFX2Handle) { return 0; }

