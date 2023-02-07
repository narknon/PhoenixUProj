#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigVariant.h"
#include "SceneRigVariants.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigVariants : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigVariant> Variants;
    
    USceneRigVariants();
};

