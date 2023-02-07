#pragma once
#include "CoreMinimal.h"
#include "BoneContainer.h"
#include "InitializeEffectorData.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FInitializeEffectorData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReference FKBone;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoneReference EffectorBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TranslationControlCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RotationControlCurve;
    
    FInitializeEffectorData();
};

