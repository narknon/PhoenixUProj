#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXOctreeFX.h"
#include "WorldFXOctreeFXInterface.generated.h"

class UObject;

UCLASS(Blueprintable, NonTransient)
class WORLDFX_API UWorldFXOctreeFXInterface : public UWorldFXOctreeFX {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> InterfaceObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtraRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bActive;
    
    UWorldFXOctreeFXInterface();
};

