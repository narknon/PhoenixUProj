#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "AblAnimationTagChooser_Array.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_Array : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblAnimationTagChooser*> TagChooserArray;
    
    UAblAnimationTagChooser_Array();
};

