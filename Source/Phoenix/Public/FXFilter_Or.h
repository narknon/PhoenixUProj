#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_Or.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_Or : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXFilter*> Filters;
    
public:
    UFXFilter_Or();
};

