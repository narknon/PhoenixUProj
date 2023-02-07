#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_SanctuaryLoadZone.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_SanctuaryLoadZone : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ZoneNameToLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreZoneLocks;
    
    USceneAction_SanctuaryLoadZone();
};

