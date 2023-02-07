#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EAcknowledgementRuleType.h"
#include "EAcknowledgementSpeakerType.h"
#include "AcknowledgementEnumsBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class UAcknowledgementEnumsBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAcknowledgementEnumsBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static FName GetEAcknowledgementSpeakerTypeNameFromID(EAcknowledgementSpeakerType inID);
    
    UFUNCTION(BlueprintCallable)
    static EAcknowledgementSpeakerType GetEAcknowledgementSpeakerTypeFromName(const FName& strName);
    
    UFUNCTION(BlueprintCallable)
    static FName GetEAcknowledgementRuleTypeNameFromID(EAcknowledgementRuleType inID);
    
    UFUNCTION(BlueprintCallable)
    static EAcknowledgementRuleType GetEAcknowledgementRuleTypeFromName(const FName& strName);
    
};

