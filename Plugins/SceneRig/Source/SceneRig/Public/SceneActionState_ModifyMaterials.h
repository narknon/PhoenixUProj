#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_AnimateCurves.h"
#include "SceneActionState_ModifyMaterials.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTexture;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_ModifyMaterials : public USceneActionState_AnimateCurves {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInstanceDynamic*, UMaterialInterface*> InstanceToOriginalMaterialMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UTexture*> OriginalTextures;
    
public:
    USceneActionState_ModifyMaterials();
};

