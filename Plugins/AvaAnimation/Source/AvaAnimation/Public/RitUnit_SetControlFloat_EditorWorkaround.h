#pragma once
#include "CoreMinimal.h"
#include "Units/RigUnit.h"
#include "RitUnit_SetControlFloat_EditorWorkaround.generated.h"

USTRUCT(BlueprintType)
struct FRitUnit_SetControlFloat_EditorWorkaround : public FRigUnitMutable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Control;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FloatValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FloatValueInEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCachedRigElement CachedControlIndex;
    
    AVAANIMATION_API FRitUnit_SetControlFloat_EditorWorkaround();
};

