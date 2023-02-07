#pragma once
#include "CoreMinimal.h"
#include "FieldGuideButtonBase.h"
#include "FieldGuideButton_Gear.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UFieldGuideButton_Gear : public UFieldGuideButtonBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> NewItemCategories;
    
public:
    UFieldGuideButton_Gear();
};

