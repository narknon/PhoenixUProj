#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsValidSubtype.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsValidSubtype : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ValidSubtypes;
    
public:
    UFXFilter_IsValidSubtype();
};

