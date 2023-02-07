#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorIsDatabaseNameConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorIsDatabaseNameConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DatabaseName;
    
    USelfActorIsDatabaseNameConsideration();
};

