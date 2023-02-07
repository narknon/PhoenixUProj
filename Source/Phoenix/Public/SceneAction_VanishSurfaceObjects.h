#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "VanishmentEvent.h"
#include "SceneAction_VanishSurfaceObjects.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_VanishSurfaceObjects : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVanishmentEvent VanishmentEvent;
    
    USceneAction_VanishSurfaceObjects();
};

