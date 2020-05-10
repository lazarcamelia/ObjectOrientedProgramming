//#include "Victim.h"
//#include "FileRepository.h"
//#include "Service.h"
//
//#include <assert.h>
//#include <fstream>
//#include <iostream>
//#include "tests.h"
//
////Domain = Victim
//void GetNameOfAVictim_ExistingInput_ReturnedString() {
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	assert(victim.getName().compare("ana") == 0);
//}
//
//void GetPlaceOfOriginOfAVictim_ExistingInput_ReturnedString() {
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	assert(victim.getPlaceOfOrigin().compare("cluj") == 0);
//}
//
//void GetAgeOfAVictim_ExistingInput_ReturnedInt() {
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	assert(victim.getAge() == 50);
//}
//
//void GetPhotoLinkOfAVictim_ExistingInput_ReturnedString() {
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	assert(victim.getPhotoLink().compare("link") == 0);
//}
//
//void GetStringOfVictim_ValidInput_ReturnString() {
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	
//	assert(victim.toString() == "ana,cluj,50,link");
//}
//
////Test Repository
//void AddVictimToRepo_ValidInput_AddedToRepo() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	FileRepository repo = FileRepository("file.txt");
//	repo.addVictim(victim);
//	assert(repo.getAllVictims().size() == 1);
//}
//
//void DeleteVictimFromRepo_ValidInput_DeletedFromRepo() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("ana", "cluj", 50, "link");
//	FileRepository repo = {"file.txt"};
//	repo.addVictim(victim);
//	repo.deleteVictim(victim);
//	assert(repo.getAllVictims().size() == 0);
//}
//
//void UpdateVictimFromRepo_ValidInput_UpdatedInRepo() {
//	Victim victim = Victim("maria", "cluj", 50, "link");
//	Victim victim2 = Victim("maria", "alba", 25, "link2");
//	FileRepository repo = {"file.txt"};
//	repo.addVictim(victim);
//	repo.updateVictim(victim2);
//	assert(repo.getAllVictims()[0].getAge() == 25);
//}
//
//
//void GetNextVictimFromRepo_ValidInput_ReturnedTheVictim() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("maria", "cluj", 50, "link");
//	Victim victim2;
//	FileRepository repo = {"file.txt"};
//	repo.addVictim(victim);
//	victim2 = repo.getNextFile();
//	assert(victim == victim2);
//}
//
//void AddVictimToAssistantFile_ValidInput_AddedToAssistantRepo() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("maria", "cluj", 50, "link");
//	Victim victim2 = Victim("ana", "alba", 25, "link2");
//	FileRepository repo = {"file.txt"};
//	repo.addVictim(victim);
//	repo.addVictim(victim2);
//	repo.addVictimToAssistantFile(victim);
//	vector<Victim> savedFiles = repo.getAllAssistantSavedFiles();
//	assert(savedFiles.size() == 1);
//}
//
//void CheckVictimInAssistantFile_ValidInput_ReturnTrue() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("maria", "cluj", 50, "link");
//	Victim victim2 = Victim("ana", "alba", 25, "link2");
//	FileRepository repo = { "file.txt" };
//	repo.addVictim(victim);
//	repo.addVictimToAssistantFile(victim);
//	assert(repo.isVictimInAssistantFile(victim) == true);
//}
//
//void CheckVictimInAssistantFile_InvalidInput_ReturnFalse() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("maria", "cluj", 50, "link");
//	Victim victim2 = Victim("ana", "alba", 25, "link2");
//	FileRepository repo = { "file.txt" };
//	repo.addVictim(victim);
//	repo.addVictimToAssistantFile(victim);
//	assert(repo.isVictimInAssistantFile(victim2) == false);
//}
//
//void CheckNextVictimInAssistantFile_ValidInput_ReturnValue() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	Victim victim = Victim("maria", "cluj", 50, "link");
//	Victim victim2 = Victim("ana", "alba", 25, "link2");
//	FileRepository repo = { "file.txt" };
//	repo.addVictim(victim);
//	repo.addVictim(victim2);
//	repo.addVictimToAssistantFile(victim);
//	repo.addVictimToAssistantFile(victim2);
//	assert(repo.getNextFile() == victim);
//	assert(repo.getNextFile() == victim2);
//	assert(repo.getNextFile() == victim);
//}
//
////Tests Service
//
//void AddVictimToService_ValidInput_AddedToService() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	Victim victim2 = Victim("maria", "alba", 25, "link2");
//	service.addVictim("maria", "alba", 25, "link2");
//	vector<Victim> allVictims = service.getAllVictims();
//	assert(allVictims[0].getName() == "maria");
//}
//
//void AddVictimToService_InvalidInput_NotAddedToService() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	Victim victim2 = Victim("maria", "alba", 25, "link2");
//	service.addVictim("maria", "alba", 25, "link2");
//	try {
//		service.addVictim("maria", "alba", 25, "link2");
//		assert(false); }
//	catch (std::exception) {
//		assert(true);
//	}
//}
//
//void DeleteVictimFromService_ValidInput_DeletedFromService() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	Victim victim2 = Victim("maria", "alba", 25, "link2");
//	service.addVictim("maria", "alba", 25, "link2");
//	service.deleteVictim("maria");
//	assert(service.getAllVictims().size() == 0);
//}
//
//void DeleteVictimFromService_InvalidInput_NotDeletedFromService() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	Victim victim2 = Victim("maria", "alba", 25, "link2");
//	service.addVictim("maria", "alba", 25, "link2");
//	try {
//		service.deleteVictim("ana");
//		assert(false); }
//	catch (std::exception) {
//		assert(true);
//	}
//}
//
//void UpdateVictimFromService_ValidInput_UpdatedInService() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	service.updateVictim("maria", "cluj", 30, "link");
//	assert(service.getAllVictims()[0].getPlaceOfOrigin().compare("cluj") == 0);
//}
//
//void UpdateVictimFromService_InvalidInput_NotUpdatedInService() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	try {
//		service.updateVictim("ana", "cluj", 30, "link");
//		assert(false); }
//	catch (std::exception) {
//		assert(true);
//	}
//}
//
//void GetNextVictimFromAssistantRepositoryService_ValidInput_ReturnedVictim() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	assert(service.getTheNextFile().getName() == "maria");
//}
//
//void AddVictimToAssistantRepoService_ValidInput_AddedToRepo() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	service.saveVictimToAssistantListOfVictims("maria");
//	vector<Victim> savedFiles = service.getTheAssistantListOfVictims();
//	assert(savedFiles.size() == 1);
//}
//
//void AddVictimToAssistantRepoService_InvalidInput_AddedToRepo() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	service.saveVictimToAssistantListOfVictims("ana");
//	vector<Victim> savedFiles = service.getTheAssistantListOfVictims();
//	assert(savedFiles.size() == 0);
//}
//
//void GetFilteredFilesFromAssistantRepoService_ValidInput_ReturnedVictims() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = {"file.txt"};
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	service.addVictim("ana", "alba", 35, "link2");
//	vector<Victim> savedFiles = service.getFiteredListOfVictimFiles("alba", 30);
//	assert(savedFiles.size() == 0);
//}
//
//void GetFilteredFilesFromAssistantRepoService_InvalidInput_ReturnedAllVictims() {
//	std::ofstream ofs("file.txt", std::ofstream::trunc);
//	FileRepository repo = { "file.txt" };
//	Service service = { repo };
//	service.addVictim("maria", "alba", 25, "link2");
//	service.addVictim("ana", "alba", 35, "link2");
//	vector<Victim> savedFiles = service.getFiteredListOfVictimFiles("", 30);
//	assert(savedFiles.size() == 2);
//}
//
//void testAll() {
//	GetNextVictimFromRepo_ValidInput_ReturnedTheVictim();
//	AddVictimToAssistantFile_ValidInput_AddedToAssistantRepo();
//
//	GetNameOfAVictim_ExistingInput_ReturnedString();
//	GetPlaceOfOriginOfAVictim_ExistingInput_ReturnedString();
//	GetAgeOfAVictim_ExistingInput_ReturnedInt();
//	GetPhotoLinkOfAVictim_ExistingInput_ReturnedString();
//	GetStringOfVictim_ValidInput_ReturnString();
//
//	AddVictimToRepo_ValidInput_AddedToRepo();
//	DeleteVictimFromRepo_ValidInput_DeletedFromRepo();
//	UpdateVictimFromRepo_ValidInput_UpdatedInRepo();
//	CheckVictimInAssistantFile_ValidInput_ReturnTrue();
//	CheckVictimInAssistantFile_InvalidInput_ReturnFalse();
//	CheckNextVictimInAssistantFile_ValidInput_ReturnValue();
//
//	AddVictimToService_ValidInput_AddedToService();
//	AddVictimToService_InvalidInput_NotAddedToService();
//	DeleteVictimFromService_ValidInput_DeletedFromService();
//	DeleteVictimFromService_InvalidInput_NotDeletedFromService();
//	UpdateVictimFromService_ValidInput_UpdatedInService();
//	UpdateVictimFromService_InvalidInput_NotUpdatedInService();
//	GetNextVictimFromAssistantRepositoryService_ValidInput_ReturnedVictim();
//	AddVictimToAssistantRepoService_ValidInput_AddedToRepo();
//	AddVictimToAssistantRepoService_InvalidInput_AddedToRepo();
//	GetFilteredFilesFromAssistantRepoService_ValidInput_ReturnedVictims();
//	GetFilteredFilesFromAssistantRepoService_InvalidInput_ReturnedAllVictims();
//}