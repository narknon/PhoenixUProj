#pragma once
#include "CoreMinimal.h"
#include "FieldGuideButtonBase.h"
#include "FieldGuideButton_Collections.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UFieldGuideButton_Collections : public UFieldGuideButtonBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> NewItemCategories;
    
public:
    UFieldGuideButton_Collections();
};

