#pragma once
#include "CoreMinimal.h"
#include "IntProvider.h"
#include "ESynchronizeMethod.h"
#include "Int_ScheduledEntitySynchronizeMethod.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UInt_ScheduledEntitySynchronizeMethod : public UIntProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESynchronizeMethod Value;
    
    UInt_ScheduledEntitySynchronizeMethod();
};

