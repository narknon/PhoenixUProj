#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_FastTravel.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_FastTravel : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Location;
    
    USceneAction_FastTravel();
};

