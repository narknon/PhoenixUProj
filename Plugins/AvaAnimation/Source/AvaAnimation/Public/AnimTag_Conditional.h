#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_Conditional.generated.h"

class UBoolProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimTag_Conditional : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationArchitectTagProvider* TagProvider;
    
    UAnimTag_Conditional();
};

