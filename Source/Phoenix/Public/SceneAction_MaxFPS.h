#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_MaxFPS.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_MaxFPS : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFPS;
    
    USceneAction_MaxFPS();
};

