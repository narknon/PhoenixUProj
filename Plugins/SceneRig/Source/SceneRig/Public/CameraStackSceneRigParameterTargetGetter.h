#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetterBlend.h"
#include "CameraStackSceneRigParameterTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackSceneRigParameterTargetGetter : public UCameraStackSecondaryTargetGetterBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ParameterName;
    
    UCameraStackSceneRigParameterTargetGetter();
};

