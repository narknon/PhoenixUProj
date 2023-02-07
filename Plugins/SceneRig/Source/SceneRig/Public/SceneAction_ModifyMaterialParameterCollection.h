#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector -FallbackName=RuntimeCurveVector
#include "RuntimeCurveVector.h"
#include "Curves/CurveFloat.h"
#include "SceneRigActionBase.h"
#include "SceneAction_ModifyMaterialParameterCollection.generated.h"

class UMaterialParameterCollection;
class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_ModifyMaterialParameterCollection : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* ParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeyTimesArePercentages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FRuntimeFloatCurve> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FRuntimeCurveVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FName, UTransformProvider*> Locations;
    
    USceneAction_ModifyMaterialParameterCollection();
};

