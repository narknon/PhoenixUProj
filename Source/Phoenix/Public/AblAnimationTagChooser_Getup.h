#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_Getup.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_Getup : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> AngleRanges;
    
    UAblAnimationTagChooser_Getup();
};

