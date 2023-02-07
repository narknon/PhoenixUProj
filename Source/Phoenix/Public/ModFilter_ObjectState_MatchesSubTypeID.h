#pragma once
#include "CoreMinimal.h"
#include "ModFilter_ObjectState_Base.h"
#include "ModFilter_ObjectState_MatchesSubTypeID.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_ObjectState_MatchesSubTypeID : public UModFilter_ObjectState_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMatchWholeWord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MatchingSubTypeID;
    
public:
    UModFilter_ObjectState_MatchesSubTypeID();
};

