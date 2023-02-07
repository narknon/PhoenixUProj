#pragma once
#include "CoreMinimal.h"
#include "FieldGuideButtonBase.h"
#include "FieldGuideButton_Challenges.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UFieldGuideButton_Challenges : public UFieldGuideButtonBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NewItemCategory;
    
public:
    UFieldGuideButton_Challenges();
};

