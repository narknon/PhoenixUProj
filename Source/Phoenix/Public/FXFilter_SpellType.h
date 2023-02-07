#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_SpellType.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_SpellType : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpellNames;
    
public:
    UFXFilter_SpellType();
};

