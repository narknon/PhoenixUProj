#pragma once
#include "CoreMinimal.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_Source_MatchesRegistryID.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_Source_MatchesRegistryID : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMatchWholeWord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MatchingRegistryID;
    
public:
    UModFilter_DealDamage_Source_MatchesRegistryID();
};

