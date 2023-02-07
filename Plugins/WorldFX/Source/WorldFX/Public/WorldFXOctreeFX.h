#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldFXOctreeFX.generated.h"

class USceneComponent;
class UWorldFXOctree;
class UWorldFXRule;

UCLASS(Abstract, Blueprintable, Transient)
class WORLDFX_API UWorldFXOctreeFX : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorldFXOctree* OwningOctree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorldFXRule* Rule;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> AttachTo;
    
    UWorldFXOctreeFX();
};

