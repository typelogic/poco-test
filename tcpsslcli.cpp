

int main (int argc, char *argv[])
{
Poco::Net::initializeSSL();
Poco::SharedPtr<Poco::Net::PrivateKeyPassphraseHandler> keyHandler = new Poco::Net::KeyFileHandler(false);
SharedPtr<InvalidCertificateHandler> invalidCertHandler = new Poco::Net::ConsoleCertificateHandler(true);

// get parameters from configuration file
unsigned short port = (unsigned short) config().getInt("tcpClient.port", 9443);

Context::Ptr pClientContext = new Context(
                    Context::CLIENT_USE,
                    Application::instance().config().getString("openSSL.client.privateKeyFile"),
                    Application::instance().config().getString("openSSL.client.certificateFile"),
                    Application::instance().config().getString("openSSL.client.caConfig"),
                    Context::VERIFY_RELAXED,
                    9,
                    true,
                    Application::instance().config().getString("openSSL.client.cipherList"));

pClientContext->enableSessionCache(true);

SSLManager::instance().initializeClient(keyHandler, invalidCertHandler, pClientContext);

Poco::Net::SocketAddress sa("127.0.0.1", port);
SecureStreamSocket ss1(sa, pClientContext);

app.logger().information("Client connecté");
	
	return 0;
}
