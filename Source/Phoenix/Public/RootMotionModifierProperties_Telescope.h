#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "UObject/NoExportTypes.h"
#include "ECustomInterpType.h"
#include "RootMotionModifierProperties_Telescope.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_Telescope : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> InterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpTime;
    
    URootMotionModifierProperties_Telescope();
};

