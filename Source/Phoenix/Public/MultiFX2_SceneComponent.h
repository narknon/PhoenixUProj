#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "Templates/SubclassOf.h"
#include "MultiFX2_SceneComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_SceneComponent : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USceneComponent> SpawnSceneComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDeactivate;
    
public:
    UMultiFX2_SceneComponent();
};

