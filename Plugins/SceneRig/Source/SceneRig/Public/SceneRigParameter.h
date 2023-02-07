#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigParameter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SCENERIG_API USceneRigParameter : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    USceneRigParameter();
};

