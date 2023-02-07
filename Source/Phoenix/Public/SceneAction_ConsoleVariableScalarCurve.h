#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_ConsoleBase.h"
#include "SceneAction_ConsoleVariableScalarCurve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ConsoleVariableScalarCurve : public USceneAction_ConsoleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInShippingToo;
    
    USceneAction_ConsoleVariableScalarCurve();
};

