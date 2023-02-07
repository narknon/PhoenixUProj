#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeFXList.h"
#include "WorldFXOctreeUnculledFX.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FWorldFXOctreeUnculledFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UObject>, FWorldFXOctreeFXList> FXMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bNewAdds;
    
    WORLDFX_API FWorldFXOctreeUnculledFX();
};

