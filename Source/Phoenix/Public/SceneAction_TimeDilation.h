#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_TimeDilation.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneAction_TimeDilation : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* DilationValueProvider;
    
    USceneAction_TimeDilation();
};

