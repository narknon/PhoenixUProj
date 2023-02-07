#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsDatabaseNameConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsDatabaseNameConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DatabaseName;
    
    UOptionActorIsDatabaseNameConsideration();
};

