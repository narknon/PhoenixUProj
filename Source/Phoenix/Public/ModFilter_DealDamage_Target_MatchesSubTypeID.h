#pragma once
#include "CoreMinimal.h"
#include "ModFilter_DealDamage_Base.h"
#include "ModFilter_DealDamage_Target_MatchesSubTypeID.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_DealDamage_Target_MatchesSubTypeID : public UModFilter_DealDamage_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMatchWholeWord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MatchingSubTypeID;
    
public:
    UModFilter_DealDamage_Target_MatchesSubTypeID();
};

