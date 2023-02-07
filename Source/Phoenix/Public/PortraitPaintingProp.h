#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PortraitPaintingComponentStates.h"
#include "PortraitPaintingProp.generated.h"

class AActor;
class APortraitPaintingActor;
class UMaterialPermuterLoadingBundle;
class UMaterialSwap;

UCLASS(Blueprintable, Transient)
class UPortraitPaintingProp : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Prop;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APortraitPaintingActor> InPortrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingBundle* MaterialBundle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPortraitPaintingComponentStates ComponentStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsHidden;
    
    UPortraitPaintingProp();
};

