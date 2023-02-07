#include "AcknowledgementEnumsBlueprintLibrary.h"

FName UAcknowledgementEnumsBlueprintLibrary::GetEAcknowledgementSpeakerTypeNameFromID(EAcknowledgementSpeakerType inID) {
    return NAME_None;
}

EAcknowledgementSpeakerType UAcknowledgementEnumsBlueprintLibrary::GetEAcknowledgementSpeakerTypeFromName(const FName& strName) {
    return EAcknowledgementSpeakerType::ANY;
}

FName UAcknowledgementEnumsBlueprintLibrary::GetEAcknowledgementRuleTypeNameFromID(EAcknowledgementRuleType inID) {
    return NAME_None;
}

EAcknowledgementRuleType UAcknowledgementEnumsBlueprintLibrary::GetEAcknowledgementRuleTypeFromName(const FName& strName) {
    return EAcknowledgementRuleType::Time;
}

UAcknowledgementEnumsBlueprintLibrary::UAcknowledgementEnumsBlueprintLibrary() {
}

