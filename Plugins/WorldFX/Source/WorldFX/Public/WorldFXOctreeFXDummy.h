#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXDummy.generated.h"

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXDummy : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtraRadius;
    
    UWorldFXOctreeFXDummy();
};

